#include "MonteCarlo.h"

/*running the random walk at each time step for each element in the price array*/
/*rterwrite to makle it more simd compatible*/
void MonteCarlo::RandomWalk(std::vector<double>& vector, double striketime, const int numberofsims,
	double interestrate, double volatility, double timestepsize, double mean,
	double standarddeviation)
{
	/*looping through each simulation held in vector*/
	//applying theparralell processing to the loop
	for (double t = 0; t <= striketime; t += timestepsize)
	{		
		/*updating vector at each time step with black scholes log random walk*/
		
		
		for (int i = 0; i < numberofsims; ++i)
		{
			vector[i] = BlackScholes(vector[i], interestrate, volatility, timestepsize, mean,
				standarddeviation);

		}
		/*if (i % 1000 == 0) 
		{
			std::cout << "Simulations completed = " << i << '\r';
		}*/
	}
}
/*This function (random walk) could be made into a mutilthreaded operation as each element in
the array is independent from another, this would increase speed*/
double MonteCarlo::BlackScholes(double currentprice, double interestrate, double volatility,
	double timestepsize, double mean, double standarddeviation) {
		/*calculating the interest component of the assest price*/
		double interest_component{};
		interest_component = (interestrate - 0.5 * std::pow(volatility,2)) * timestepsize;

		//normal random number genrator centered on a goven mean with a given standard deviation
		std::random_device r; //settig a random seed
		std::default_random_engine generator(r()); //random generator form the random seed
		std::normal_distribution<double> distribution(mean, standarddeviation);

		/*calculating the random component of the price*/
		double random_component{};
		random_component = volatility * std::sqrt(timestepsize) * distribution(generator);

		/*returning the updated assest price*/
		return currentprice * std::exp(interest_component + random_component);
		}

/*this function determines the number of monte carlo simulations required for a 95% confidence*/
int MonteCarlo::NumberOfRuns(std::vector<double>& vector) {
	double StdDev{};
	StdDev = StDev(vector);
	int runs{};
	runs = std::pow(1.96 * StdDev / 0.01, 2);
	return runs;
}

