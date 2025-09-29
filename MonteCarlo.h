#ifndef MONTECARLO
#define MONTECARLO


#include <random>
#include <numeric>
#include <immintrin.h>

#include "Contract.h"
#include "statistics.h"



	void RandomWalk(const std::unique_ptr<Contract>& obj);

	std::vector<double> RandomVector(const std::unique_ptr<Contract>& obj);

	double BlackScholes(double currentprice, const std::unique_ptr<Contract>& obj,
		const double randomnumber);

	/*int NumberOfRuns(std::vector<double>& vector);

	std::vector<double> simd128BlackScholes(std::vector<double> currentprice, double interestrate, double volatility,
		double timestepsize, double mean, double standarddeviation);

	std::vector<double> simd256BlackScholes(std::vector<double> currentprice, double interestrate,
		double volatility, double timestepsize, double mean, double standarddeviation);
};*/





#endif
