#ifndef MONTECARLO
#define MONTECARLO

#include "statistics.h"

class MonteCarlo: public Statistics {
private:

public:
	
	void RandomWalk(std::vector<double>& vector, double striketime, int numberofsims,
		double interestrate, double volatility, double timestepsize, double mean,
		double standarddeviation);
	
	double BlackScholes(double currentprice, double interestrate, double volatility,
		double timestepsize, double mean, double standarddeviation);

	int NumberOfRuns(std::vector<double>& vector);
};





#endif
