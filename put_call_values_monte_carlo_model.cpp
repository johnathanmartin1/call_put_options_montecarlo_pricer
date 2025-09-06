// put_call_values_monte_carlo_model.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <random>
#include <ctime>
#include <numeric>
float initial_price{ 100 };

float interest_rate{ 0.05 };

float volatility{ 0.2 };

float time_step_size{ 0.01 };

float strike_time{ 1 };

static const int number_of_sims{ 10000 };

float strike_price{ 115 };

float mean{ 0 };

float standard_distribution{ 1 };



float random_walk(float x) {
	/*calculating the interest component of the assest price*/
	float interest_component{};
	interest_component = (interest_rate - 0.5 * volatility * volatility) * time_step_size;
	
	//normal random number genrator centered on a goven mean with a given standard deviation
	std::random_device r; //settig a random seed
	std::default_random_engine generator(r()); //random generator form the random seed
	std::normal_distribution<float> distribution(mean, standard_distribution); 
	
	/*calculating the random component of the price*/
	float random_component{};
	random_component = volatility * std::sqrt(time_step_size) * distribution(generator);
	
	/*returning the updated assest price*/
	return x * std::exp(interest_component + random_component);
}

float option_value(float x) {
	/*return the asses option value based on the call or put totals of the simulation*/
	return (x / number_of_sims) * std::exp(-interest_rate * strike_time);
}

int main()
{
	
	/*intialised array with intial starting price given to all sims*/
	float prices[number_of_sims] = {}; 
	for (int i = 0; i < number_of_sims; ++i) {
		prices[i] = initial_price;
	}

	/*running the random walk at each time step for each element in the price array*/
	for (int t = 1; t <= strike_time/time_step_size; ++t) {
		/*running through the price array and updating with the random walk pricing*/
		for (int i = 0; i < number_of_sims; ++i) {
			prices[i] = random_walk(prices[i]);
			//std::cout << "prices in progress " << prices[i] << std::endl;
		}
	}
	//array size total bytes divded by a single emlements bytes gives the total number of elements
	//std::cout << sizeof(prices)/ sizeof(prices[0]);
	float total_value_of_sims{0};
	for (int i = 0; i < number_of_sims; ++i) {
		total_value_of_sims += prices[i];
		//std::cout << "running total "<<total_value_of_sims<< std::endl;
	}
	/*Calculating the average price across the various simulations at strike time*/
	float monte_carlo_price{};
	monte_carlo_price = total_value_of_sims / (sizeof(prices) / sizeof(prices[0]));
	std::cout << "monte carlo price at strike time " << monte_carlo_price << '\n';

	/*calculating the put and call total values from the simulation at strike time*/
	float put_total{ 0 };
	float call_total{ 0 };
	float price_strike_difference{};
	for (int i = 0; i < number_of_sims; ++i) {
		float price_strike_difference{};
		price_strike_difference = prices[i] - strike_price;
		if (price_strike_difference > 0) {
			put_total += price_strike_difference;
		}
		if (price_strike_difference < 0) {
			call_total += -1 * price_strike_difference;
		}
	}

	std::cout << "put value " << option_value(put_total) << '\n';
	std::cout << "call value " << option_value(call_total) << '\n';


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
