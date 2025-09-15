#include <iostream>
#include <vector>
#include <numeric>

#include "statistics.h"

/*Calculates the mean value of a vector*/
double mean(std::vector<double>& vector) {

	double sum{ 0 };
	for (int i = 0; i < vector.size(); i++) {
		sum += vector[i];
	}
	return sum / vector.size();
}

/*calculates the standard deviation of a vector*/
double stdev(std::vector<double>& vector) {
	
	double sum{ 0 };
	double average{ mean(vector) };
	for (int i = 0; i < vector.size(); i++) {
		sum += std::pow(vector[i] - average, 2);
	}
	return std::sqrt(sum / vector.size());
}
