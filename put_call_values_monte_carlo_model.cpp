// put_call_values_monte_carlo_model.cpp : This file contains the 'main' function. Program execution begins and ends here.
//

#include <iostream>
#include <chrono>

#include "Factories.h"
#include "MonteCarlo.h"


int main()
{
	
	{
		std::unique_ptr<Contract> asian = createcontract("Asian");
		asian -> setStrikeTime(0.08); //strike time in years
		asian -> setStartingPrice(100);

		//asian -> setInterestRate(0.05);

		//asian -> setVolatility(0.2);

		//asian -> setStrikePrice(115);

		//asian -> setTimeStepSize(2.6E-3);

		//asian -> setRandomMean(0);

		//asian -> setStandardDeviation(1);

		//asian -> setNumberOfSimulations(10000);
		
		//asian -> setDrift(0.05);
		
		asian->Variables();
		auto start = std::chrono::high_resolution_clock::now();
		MonteCarlo::AutoPrecisionRandomWalk(asian); 
		//MonteCarlo::simd128RandomWalk(asian);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		asian->AverageStrikePrice();
		asian->Value();
		asian->type();
		std::cout << "Elapsed time to run Monte Carlo function: " << elapsed.count() << " seconds\n\n";
	}
	
	{
		std::unique_ptr<Contract> european = createcontract("European");
		european->setStrikeTime(0.08); //strike time in years

		//european -> setInterestRate(0.05);

		//european -> setVolatility(0.2);

		//european -> setStrikePrice(115);

		//european -> setTimeStepSize(2.6E-3);

		//european -> setRandomMean(0);

		//european -> setStandardDeviation(1);

		//european -> setNumberOfSimulations(10000);

		//european -> setDrift(0.05);

		european->Variables();
		auto start = std::chrono::high_resolution_clock::now();
		MonteCarlo::AutoPrecisionRandomWalk(european); 
		//MonteCarlo::simd128RandomWalk(european);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		european->AverageStrikePrice();
		european->CallValue();
		european->PutValue();
		european->type();
		std::cout << "Elapsed time to run Monte Carlo function: " << elapsed.count() << " seconds\n\n";
	}
	
	return 0;
}
