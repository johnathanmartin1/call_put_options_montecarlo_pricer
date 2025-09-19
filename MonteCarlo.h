#ifndef MONTECARLO
#define MONTECARLO

#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <immintrin.h>

#include "statistics.h"

class MonteCarlo : public Statistics 
{
/*-------------------------------------------------------------------------------------------------*/
private:

/*-------------------------------------------------------------------------------------------------*/
public:

	void RandomWalk(std::vector<double>& vector, double striketime, int numberofsims,
		double interestrate, double volatility, double timestepsize, double mean,
		double standarddeviation);

	double BlackScholes(double currentprice, double interestrate, double volatility,
		double timestepsize, double mean, double standarddeviation);

	int NumberOfRuns(std::vector<double>& vector);

	std::vector<double> simd128BlackScholes(std::vector<double> currentprice, double interestrate, double volatility,
		double timestepsize, double mean, double standarddeviation);

	std::vector<double> simd256BlackScholes(std::vector<double> currentprice, double interestrate,
		double volatility, double timestepsize, double mean, double standarddeviation);
};





#endif
