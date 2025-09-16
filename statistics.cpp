#include <iostream>
#include <vector>
#include <numeric>

#include "statistics.h"

/*Calculates the mean value of a vector*/
double Statistics::Mean(std::vector<double>& vector) 
{
	double sum{ 0 };
	
	for (double element: vector) 
	{
		sum += element;
	}
	
	return sum / vector.size();
}

/*calculates the standard deviation of a vector*/
double Statistics::StDev(std::vector<double>& vector)
{	
	double sum{ 0 };
	double average{ Mean(vector) };
	
	for (double element: vector) 
	{
		sum += std::pow(element - average, 2);
	}
	
	return std::sqrt(sum / vector.size());
}
