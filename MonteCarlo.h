#ifndef MONTECARLO
#define MONTECARLO


#include <random>
#include <numeric>
#include <immintrin.h> //for intrinsic simd commands
#include <utility> //for std::pair

#include "Contract.h"
#include "statistics.h"

namespace MonteCarlo
{
	void RandomWalk(const std::unique_ptr<Contract>& obj);

	double BlackScholes(double currentprice, const std::unique_ptr<Contract>& obj,
		const double randomnumber);

	void simd128RandomWalk(const std::unique_ptr<Contract>& obj);

	 std::vector<double> simd128BlackScholes( const std::vector<double>& currentprice,
		 const std::unique_ptr<Contract>& obj, const std::vector<double>& randomnumber);
	 //, const std::vector<double>& average);

	int NumberOfRuns(const std::unique_ptr<Contract>& obj);

	void AutoPrecisionRandomWalk(const std::unique_ptr<Contract>& obj);
}
	

	//std::vector<double> simd256BlackScholes(std::vector<double> currentprice, double interestrate,
	//	double volatility, double timestepsize, double mean, double standarddeviation);






#endif
