// put_call_values_monte_carlo_model.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory> 
#include <random>
#include <numeric>
#include <vector>

#include "Option.h"
#include "statistics.h"


/*This function (random walk) could be made into a mutilthreaded operation as each element in
the array is independent from another, this would increase speed*/
float random_walk(double current_price, double interest_rate, double volatility,
	double time_step_size, double mean, double standard_deviation) {
	/*calculating the interest component of the assest price*/
	float interest_component{};
	interest_component = (interest_rate - 0.5 * volatility * volatility) * time_step_size;
	
	//normal random number genrator centered on a goven mean with a given standard deviation
	std::random_device r; //settig a random seed
	std::default_random_engine generator(r()); //random generator form the random seed
	std::normal_distribution<float> distribution(mean, standard_deviation); 
	
	/*calculating the random component of the price*/
	float random_component{};
	random_component = volatility * std::sqrt(time_step_size) * distribution(generator);
	
	/*returning the updated assest price*/
	return current_price * std::exp(interest_component + random_component);
}

float option_value(double total_value_sum, double number_of_sims, double interest_rate,
	double strike_time) {
	/*return the asses option value based on the call or put totals of the simulation*/
	return (total_value_sum / number_of_sims) * std::exp(-interest_rate * strike_time);
}

int main()
{
	Contract test{};
	
	/*intialised array with intial starting price given to all sims*/
	//double prices[test.getNumberOfSimulations()] = {};
	std::vector<double> prices;

	for (int i = 0; i < test.getNumberOfSimulations(); ++i) {
		prices.push_back(test.getStartingPrice());
		//prices[i] = test.getStartingPrice();
	}

	/*running the random walk at each time step for each element in the price array*/
	for (double t = 0.01; t <= test.getStrikeTime(); t+=0.01) {
		/*running through the price array and updating with the random walk pricing*/
		for (int i = 0; i < test.getNumberOfSimulations(); ++i) {
			prices[i] = random_walk(prices[i],test.getInterestRate(), test.getVolatility(),
				test.getTimeStepSize(), test.getMean(), test.getStandardDeviation());
			//std::cout << "prices in progress " << prices[i] << std::endl;
		}
	}
	//array size total bytes divded by a single emlements bytes gives the total number of elements
	//std::cout << sizeof(prices)/ sizeof(prices[0]);
	double total_value_of_sims{0};
	
	for (int i = 0; i < test.getNumberOfSimulations(); ++i) {
		total_value_of_sims += prices[i];
		//std::cout << "running total "<<total_value_of_sims<< std::endl;
	}
	
	
	std::cout << "Asset price at strike time " << char(156) << mean(prices) << '\n';

	/*calculating the put and call total values from the simulation at strike time
	this could be put into a function*/
	float put_total{ 0 };
	
	float call_total{ 0 };
	
	float price_strike_difference{};
	
	for (int i = 0; i < test.getNumberOfSimulations(); ++i) {
	
		float price_strike_difference{};
		
		price_strike_difference = prices[i] - test.getStrikePrice();
		
		if (price_strike_difference > 0) {
		
			put_total += price_strike_difference;
		}
		if (price_strike_difference < 0) {
			
			call_total += -1 * price_strike_difference;
		}
	}
	/*add output stating the users chosen variables*/

	/*print out put and call values to terminal*/
	std::cout << "Put value at strike time " << char(156) << option_value(put_total,
		test.getNumberOfSimulations(), test.getInterestRate(), test.getStrikeTime()) << '\n';
	
	std::cout << "Call value at strike time " << char(156) << option_value(call_total,
		test.getNumberOfSimulations(), test.getInterestRate(), test.getStrikeTime()) << '\n';

	
	return 0;
}

