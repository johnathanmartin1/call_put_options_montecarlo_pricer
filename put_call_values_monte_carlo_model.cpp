// put_call_values_monte_carlo_model.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory> 
#include <random>
#include <numeric>
#include <vector>

#include "Option.h"
#include "statistics.h"

int main()
{
	Contract test{};
	test.MonteCarlo();
	
	Contract test2{};
	test2.MonteCarloAuto();

	test2.AverageStrikePrice();
	test2.CallValue();
	test2.PutValue();

	
	return 0;
}

