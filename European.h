#ifndef EUROPEAN
#define EUROPEAN

#include "Contract.h"

class European : public Contract
{
public:
	~European()
	{
		std::cout << "European option deleted\n";
		std::cout << "------------------end of option------------------\n\n\n";
	}

	void type() override {
		std::cout << "Contract type is European\n\n";	
	}
	
	/*functions for calculating the call and put values*/
	double OptionValue(const double sumoptionvalue);

	double PutValueCalc(const std::vector<double>& vector);

	double CallValueCalc(const std::vector<double>& vector);

	double PutValueError(const std::vector<double>& vector);

	double CallValueError(const std::vector<double>& vector);

	void PutValue() override;

	void CallValue() override;
};









#endif
