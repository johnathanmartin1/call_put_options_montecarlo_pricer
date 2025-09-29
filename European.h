#ifndef EUROPEAN
#define EUROPEAN

#include "Contract.h"

class European : public Contract
{
public:
	void type() override {
		std::cout << "Contract type is European\n\n";
	}

	~European()
	{
		std::cout << "European option deleted\n";
	}
	
	/*functions for calculating the call and put values*/
	double OptionValue(const double sumoptionvalue);// override;

	double PutValueCalc(const std::vector<double>& vector);// override;

	double CallValueCalc(const std::vector<double>& vector);// override;

	double PutValueError(const std::vector<double>& vector);// override;

	double CallValueError(const std::vector<double>& vector);// override;

	void PutValue() override;

	void CallValue() override;
};









#endif
