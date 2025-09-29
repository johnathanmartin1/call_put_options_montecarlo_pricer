// put_call_values_monte_carlo_model.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>

//#include "Option.h"
//#include "MonteCarlo.h"

//int main()
//{
//	{/*test 1 without any simd calculations*/
//		Contract test{};
//
//		test.Variables();  //only calling this once as both tests are running the same default variables
//
//		std::cout << "\n\n\n------------Test 1 No SIMD Instructions------------\n\n\n";
//
//		auto start = std::chrono::high_resolution_clock::now();
//
//		test.MonteCarloAuto();
//
//		auto end = std::chrono::high_resolution_clock::now();
//
//		std::chrono::duration<double> elapsed = end - start;
//
//		test.AverageStrikePrice();
//
//		test.CallValue();
//
//		test.PutValue();
//
//		std::cout << "Elapsed time to run Monte Carlo function: " << elapsed.count() << " seconds\n\n\n\n";
//	}
//	
//	
//	/*---------------------------------------------------------------------------------------------*/
//	{/*test 2 with simd calculations*/
//		Contract test{};
//
//		std::cout << "\n\n\n------------Test 2 With SIMD Instructions------------\n\n\n";
//
//		auto start = std::chrono::high_resolution_clock::now();
//
//		/*My computer can only do the 128 bit simd operations as its very old. I assume your equipment
//		will be able to handle the 256 bit one, but I have not tested if it works*/
//		test.simd128MonteCarloAuto();        //comment out as appropriate 
//		//test2.simd256MonteCarloAuto();
//
//		auto end = std::chrono::high_resolution_clock::now();
//
//		std::chrono::duration<double> elapsed = end - start;
//
//		test.AverageStrikePrice();
//
//		test.CallValue();
//
//		test.PutValue();
//
//		std::cout << "Elapsed time to run Monte Carlo function: " << elapsed.count() << " seconds\n\n\n\n";
//	}
//	
//	std::cout << "Press Enter to exit";
//	std::cin.get();
//	return 0;
//}

//int main()
//{
//
//	std::unique_ptr<Contract> test = std::make_unique<Contract>();
//	RandomWalk(test);
//	test->Variables();
//	test->AverageStrikePrice(test);
//	test->PutValue(test);
//	test->CallValue(test);
//	return 0;
//}

#include "Factories.h"
#include "MonteCarlo.h"
#include <memory>
int main()
{
	//{
	//	std::unique_ptr<Contract> asian = createcontract("Asian");
	//	std::cout << asian->getStartingPrice() << '\n';
	//	asian->setStartingPrice(140);
	//	std::cout << asian->getStartingPrice() << '\n';
	//	RandomWalk(asian);
	//	std::cout << Mean(asian->getPrices()) << '\n';
	//	asian->test();
	//	asian->AverageStrikePrice();
	//	//asian->CallValue();
	//	//asian->PutValue();
	//}

	std::unique_ptr<Contract> european = createcontract("European");
	european->Variables();
	RandomWalk(european);
	european->AverageStrikePrice();
	european->CallValue();
	european->PutValue();
	european->type();
	return 0;
}
