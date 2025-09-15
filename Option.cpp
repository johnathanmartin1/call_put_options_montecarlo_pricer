#include <iostream>
#include <memory>
#include <vector>

#include "Option.h"
#include "statistics.h"

/*constructor for an object with class "Option" with sanity checjks on inoputted variabels*/

Contract::Contract(double startingprice, double interestrate, double volatility,
	double strikeprice, double striketime, double timestepsize ,
	double mean, double standarddeviation, int numberofsimulations) :
	StartingPrice(std::make_unique<double>(startingprice)),
	InterestRate(std::make_unique<double>(interestrate)),
	Volatility(std::make_unique<double>(volatility)),
	StrikePrice(std::make_unique<double>(strikeprice)),
	StrikeTime(std::make_unique<double>(striketime)),
	TimeStepSize(std::make_unique<double>(timestepsize)),
	Mean(std::make_unique<double>(mean)),
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

void Contract::setMean(double newmean) 
{
	Mean = std::move(std::make_unique<double>(newmean));
}

void Contract::setStandardDeviation(double newstandarddeviation) 
{
	StandardDeviation = std::move(std::make_unique<double>(newstandarddeviation));
}

void Contract::setNumberOfSimulations(int newnumberofsimulations) 
{
	NumberOfSimulations = std::move(std::make_unique<int>(newnumberofsimulations));
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

double Contract::getMean() 
{
	return *Mean;
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

/*intialises the price vector with the atrting price with the required number of simulations*/
void Contract::VectorIntialisation(std::vector<double>& prices, int sims, double price) {
	prices.assign(sims, price);
}