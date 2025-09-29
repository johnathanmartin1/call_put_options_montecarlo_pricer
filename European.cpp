#include "European.h"

/*Produces the value of a contracts option absed on the call/pit sums of the simulation*/
double European::OptionValue(const double sumoptionvalue) {
	return (sumoptionvalue / getNumberOfSimulations()) *
		std::exp(-getInterestRate() * getStrikeTime());
}

/*prints the put value of an option with the associated errors*/
void European::PutValue()
{
	std::vector<double> priceplus;
	std::vector<double> priceminus;
	double valueerror{};
	valueerror = PutValueError(getPrices());
	for (double val : getPrices())
	{
		priceplus.push_back(val + valueerror);
		priceminus.push_back(val - valueerror);
	}
	double uppererror{};
	double lowererror{};
	double averagevalue{};
	uppererror = PutValueCalc(priceplus);
	lowererror = PutValueCalc(priceminus);
	averagevalue = PutValueCalc(getPrices());
	std::cout << "Put value = " << char(156) << averagevalue << "    ( + " <<
		uppererror - averagevalue << " - " << averagevalue - lowererror << " )\n\n";
}

/*returns the put option value*/
double European::PutValueCalc(const std::vector<double>& vector)
{
	double puttotal{};

	for (int i = 0; i < getNumberOfSimulations(); ++i)
	{
		double pricestrikedifference{};

		pricestrikedifference = vector[i] - getStrikePrice();

		if (pricestrikedifference > 0)
		{
			puttotal += pricestrikedifference;
		}

	}


	return OptionValue(puttotal);
}

/*returns the error in the put option value with a 95% confidence window*/
double European::PutValueError(const std::vector<double>& vector)
{
	std::vector<double>pricediff;
	for (double i : vector)
	{
		double diff{};
		diff = vector[i] - getStrikePrice();
		if (diff > 0)
		{
			pricediff.push_back(diff);
		}
	}

	double dev = StDev(pricediff);
	return 1.96 * dev;
}

/*returns the error in the call option value with a 95% confidnece window*/
double European::CallValueError(const std::vector<double>& vector)
{
	std::vector<double>pricediff;
	for (double i : vector)
	{
		double diff{};
		diff = vector[i] - getStrikePrice();
		if (diff < 0)
		{
			pricediff.push_back(-1 * diff);
		}
	}

	double dev = StDev(pricediff);
	return 1.96 * dev;
}

/*prints the call value option wiht its associated errors*/
void European::CallValue()
{
	std::vector<double> priceplus;
	std::vector<double> priceminus;
	double valueerror{};
	valueerror = CallValueError(getPrices());
	for (double val : getPrices())
	{
		priceplus.push_back(val - valueerror);
		priceminus.push_back(val + valueerror);
	}
	double uppererror{};
	double lowererror{};
	double averagevalue{};
	uppererror = CallValueCalc(priceplus);
	lowererror = CallValueCalc(priceminus);
	averagevalue = CallValueCalc(getPrices());
	std::cout << "Call value = " << char(156) << averagevalue << "    ( + " <<
		uppererror - averagevalue << " - " << averagevalue - lowererror << " )\n\n";
}

/*returns the call option value*/
double European::CallValueCalc(const std::vector<double>& vector)
{
	double calltotal{};

	for (int i = 0; i < getNumberOfSimulations(); ++i)
	{

		double pricestrikedifference{};

		pricestrikedifference = vector[i] - getStrikePrice();

		if (pricestrikedifference < 0)
		{
			calltotal += -1 * pricestrikedifference;
		}
	}
	return OptionValue(calltotal);
}