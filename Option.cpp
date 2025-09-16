#include <iostream>
#include <memory>
#include <vector>

#include "Option.h"
//#include "statistics.h"
//#include "MonteCarlo.h"

/*constructor for an object with class "Option" with sanity checjks on inoputted variabels*/

Contract::Contract(double startingprice, double interestrate, double volatility,
	double strikeprice, double striketime, double timestepsize ,
	double randommean, double standarddeviation, int numberofsimulations) :
	StartingPrice(std::make_unique<double>(startingprice)),
	InterestRate(std::make_unique<double>(interestrate)),
	Volatility(std::make_unique<double>(volatility)),
	StrikePrice(std::make_unique<double>(strikeprice)),
	StrikeTime(std::make_unique<double>(striketime)),
	TimeStepSize(std::make_unique<double>(timestepsize)),
	RandomMean(std::make_unique<double>(randommean)),
	StandardDeviation(std::make_unique<double>(standarddeviation)),
	NumberOfSimulations(std::make_unique<int>(numberofsimulations))
{
	/*Sanity checks on the input*/
	while (*StartingPrice <= 0) 
	{
		std::cerr << "Starting price must be a number greater than " << char(156) << "0.00\n";
		std::cout << "Please enter a starting price: " << std::endl;
		double newstartprice{};
		std::cin >> newstartprice;
		setStartingPrice(newstartprice);
	}
	
	/*Intialising the vector of prices for each simulation*/
	VectorIntialisation(prices, getNumberOfSimulations(), getStartingPrice());
	
	
};

/*-------------------------------------------------------------------------------------------------*/
/*setters for the variables for objects with class "Contract"*/
void Contract::setStartingPrice(double newstartingprice) 
{
	StartingPrice = std::move(std::make_unique<double>(newstartingprice));

	/*Sanity checks on the input*/
	while (*StartingPrice <= 0)
	{
		std::cerr << "Starting price must be a number greater than " << char(156) << "0.00\n";
		std::cout << "Please enter a starting price: " << std::endl;
		double newstartprice{};
		std::cin >> newstartprice;
		setStartingPrice(newstartprice);
	}
	VectorIntialisation(prices, getNumberOfSimulations(), getStartingPrice());
}

void Contract::setInterestRate(double newinterestrate) 
{
	InterestRate = std::move(std::make_unique<double>(newinterestrate));
}

void Contract::setVolatility(double newvolatility) 
{
	Volatility = std::move(std::make_unique<double>(newvolatility));
}

void Contract::setStrikePrice(double newstrikeprice) 
{
	StrikePrice = std::move(std::make_unique<double>(newstrikeprice));
}

void Contract::setStrikeTime(double newstriketime) 
{
	StrikeTime = std::move(std::make_unique<double>(newstriketime));
}

void Contract::setTimeStepSize(double newtimestepsize) 
{
	TimeStepSize = std::move(std::make_unique<double>(newtimestepsize));
}

void Contract::setRandomMean(double newmean) 
{
	RandomMean = std::move(std::make_unique<double>(newmean));
}

void Contract::setStandardDeviation(double newstandarddeviation) 
{
	StandardDeviation = std::move(std::make_unique<double>(newstandarddeviation));
}

void Contract::setNumberOfSimulations(int newnumberofsimulations) 
{
	NumberOfSimulations = std::move(std::make_unique<int>(newnumberofsimulations));
	
	VectorIntialisation(prices, getNumberOfSimulations(), getStartingPrice());
}

/*-------------------------------------------------------------------------------------------------*/
/*getters for objects with class "Contract"*/
double Contract::getStartingPrice() 
{
	return *StartingPrice;
}

double Contract::getInterestRate() 
{
	return *InterestRate;
}

double Contract::getVolatility() 
{
	return *Volatility;
}

double Contract::getStrikePrice() 
{
	return *StrikePrice;
}

double Contract::getStrikeTime() 
{
	return *StrikeTime;
}

double Contract::getTimeStepSize() 
{
	return *TimeStepSize;
}

double Contract::getRandomMean() 
{
	return *RandomMean;
}

double Contract::getStandardDeviation() 
{
	return *StandardDeviation;
}

int Contract::getNumberOfSimulations() 
{
	return *NumberOfSimulations;
}

/*-------------------------------------------------------------------------------------------------*/
/*functions for Contract class*/

/*intialises the price vector with the startting price with the required number of simulations*/
void Contract::VectorIntialisation(std::vector<double>& prices, int sims, double price) 
{
	prices.assign(sims, price);
}

/*runs a monte carlo simulation with the chosen number of runs*/
void Contract::MonteCarlo() 
{
	RandomWalk(prices, getStrikeTime(), getNumberOfSimulations(), getInterestRate(),
		getVolatility(), getTimeStepSize(), getRandomMean(), getStandardDeviation());
}

/*runs a monte carlo simulation with the number of runs required for 95% cofidence interval */
void Contract::MonteCarloAuto()
{
	setNumberOfSimulations(2000);

	MonteCarlo();
	
	setNumberOfSimulations(NumberOfRuns(prices));
	
	std::cout << "The number of required simulations for 95% accuracy is " <<
		getNumberOfSimulations() << '\n';
	
	MonteCarlo();
}

/*Produces the value of a contracts option absed on the call/pit sums of teh simulation*/
double Contract::OptionValue(double sumoptionvalue) {
	return (sumoptionvalue / getNumberOfSimulations()) *
		std::exp(-getInterestRate() * getStrikeTime());
}

/*prints the put option value*/
void Contract::PutValue() 
{
	double puttotal{};
	
	for (int i = 0; i < getNumberOfSimulations(); ++i)
	{

		double pricestrikedifference{};

		pricestrikedifference = prices[i] - getStrikePrice();

		if (pricestrikedifference > 0)
		{
			puttotal += pricestrikedifference;
		}
		
	}
	std::cout << "Put value = "<< char(156) << OptionValue(puttotal) << '\n';
}

/*prints the call option value*/
void Contract::CallValue()
{
	double calltotal{};

	for (int i = 0; i < getNumberOfSimulations(); ++i)
	{

		double pricestrikedifference{};

		pricestrikedifference = prices[i] - getStrikePrice();

		if (pricestrikedifference < 0)
		{
			calltotal += -1 * pricestrikedifference;
		}
	}
	std::cout << "Call value = "<<char(156)<< OptionValue(calltotal) << '\n';
}

/*prints the average price of the assest at strike time*/
void Contract::AverageStrikePrice()
{
	std::cout << "Average assest price at strike time :" << char(156) << Mean(prices) << '\n';
}
