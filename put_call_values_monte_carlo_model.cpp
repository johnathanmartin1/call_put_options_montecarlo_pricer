// put_call_values_monte_carlo_model.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>

#include "Option.h"

int main()
{
	
	/*test 1 without any simd calculations*/
	Contract test1{};

	test1.Variables();  //only calling this once as both tests are running the same default variables

	std::cout << "\n\n\n------------Test 1 no SIMD instructions------------\n\n\n";

	auto start = std::chrono::high_resolution_clock::now();
	
	test1.MonteCarloAuto();
	
	auto end = std::chrono::high_resolution_clock::now();
	
	std::chrono::duration<double> elapsed = end - start;
	
	test1.AverageStrikePrice();
	
	test1.CallValue();
	
	test1.PutValue();

	std::cout << "Elapsed time to run function: " << elapsed.count() << " seconds\n\n\n\n";

	
	
	/*---------------------------------------------------------------------------------------------*/
	/*test 2 with simd calculations*/
	Contract test2{};

	std::cout << "\n\n\n------------test 2 with SIMD instructions------------\n\n\n";

	auto start1 = std::chrono::high_resolution_clock::now();

	/*My computer can only do the 128 bit simd operations as its very old. I assume your equipment
	will be able to handle the 256 bit one, but I have not tested if it works*/
	test2.simd128MonteCarloAuto();        //comment out as appropriate 
	//test2.simd256MonteCarloAuto();

	auto end1 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed1 = end1 - start1;

	test2.AverageStrikePrice();

	test2.CallValue();

	test2.PutValue();

	std::cout << "Elapsed time to run function: " << elapsed1.count() << " seconds\n\n\n\n";
	
	return 0;
}

