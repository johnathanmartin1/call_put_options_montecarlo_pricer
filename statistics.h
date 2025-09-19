#ifndef STATISTICS_PACKAGE
#define STATISTICS_PACKAGE

#include <iostream>
#include <vector>
#include <numeric>

class Statistics 
{
/*-------------------------------------------------------------------------------------------------*/
private:

/*-------------------------------------------------------------------------------------------------*/
public:

	double Mean(std::vector<double>& vector);

	double StDev(std::vector<double>& vector);

	double ConfidenceInterval(std::vector<double>& vector);

};

#endif

