#ifndef ASIAN
#define ASIAN

#include <iostream>

#include "Contract.h"
#include "Statistics.h"

class Asian : public Contract
{
public:

	~Asian() 
	{
		std::cout << "Asian option deleted\n";
		std::cout << "------------------end of option------------------\n\n\n";
	}
	
	void type() override {
		std::cout << "Contract type is Asian\n\n";
	}

	void Value() override;

	std::vector<double> Payoff(const std::vector<double>& vector);

	
};





#endif
