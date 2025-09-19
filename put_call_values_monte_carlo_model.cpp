// put_call_values_monte_carlo_model.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>

#include "Option.h"

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	
	Contract test2{0};
	
	test2.MonteCarloAuto();
	
	auto end = std::chrono::high_resolution_clock::now();
	
	std::chrono::duration<double> elapsed = end - start;
	
	std::cout << "Elapsed time to run function: " << elapsed.count() << " seconds\n";
	
	test2.AverageStrikePrice();
	
	test2.CallValue();
	
	test2.PutValue();

	return 0;
}

