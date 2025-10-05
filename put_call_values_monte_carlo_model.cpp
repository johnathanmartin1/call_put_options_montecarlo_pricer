// put_call_values_monte_carlo_model.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>

#include "Factories.h"
#include "MonteCarlo.h"


int main()
{
	{
		std::unique_ptr<Contract> asian = createcontract("Asian");
		asian->setStrikeTime(.08);
		asian->Variables();
		auto start = std::chrono::high_resolution_clock::now();
		MonteCarlo::RandomWalk(asian);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		asian->AverageStrikePrice();
		asian->Value();
		asian->type();
		std::cout << "Elapsed time to run Monte Carlo function: " << elapsed.count() << " seconds\n\n";
	}
	
	{
		std::unique_ptr<Contract> european = createcontract("European");
		european->setStrikeTime(.08);
		european->Variables();
		auto start = std::chrono::high_resolution_clock::now();
		MonteCarlo::simd128RandomWalk(european);
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
