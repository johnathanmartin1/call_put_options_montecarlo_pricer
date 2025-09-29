//#ifndef Contracts
//#define Contracts
//
//#include <iostream>
//#include <limits>
//#include <memory>
//#include <vector>
//#include "statistics.h"
//
//class Contract
//{
///*-------------------------------------------------------------------------------------------------*/
//private:
//	double StartingPrice;
//	double InterestRate;
//	double Volatility;
//	double TimeStepSize;
//	double StrikeTime;
//	double StrikePrice;
//	double RandomMean;
//	double StandardDeviation;
//	int NumberOfSimulations;
//	std::vector<double>* prices = new std::vector<double>{};
//
//
///*-------------------------------------------------------------------------------------------------*/
//public:
//	/*forward declaration for the constructor of this class*/
//	Contract(double startingprice = 114.5, double interestrate = 0.05, double volatility = 0.2,
//		double strikeprice = 115, double striketime = 1, double timestepsize = 2.6E-3,
//		double randommean = 0, double standarddeviation = 1, int numberofsimulations = 1000);
//	
//	/*forward declaration for the destructor of this class*/
//	~Contract();
//
//
//	/*---------------------------------------------------------------------------------------------*/
//	/*Sanity check functions*/
//	void SanityCheckStartingPrice();
//
//	void SanityCheckInterestRate();
//
//	void SanityCheckVolatility();
//
//	void SanityCheckStrikePrice();
//
//	void SanityCheckStrikeTime();
//
//	void SanityCheckTimeStepSize();
//
//	void SanityCheckRandomMean();
//
//	void SanityCheckStandardDeviation();
//
//	void SanityCheckNumberOfSimulations();
//
//
//    /*---------------------------------------------------------------------------------------------*/
//	/*forward declaration for "setters for the variables"*/
//	void setStartingPrice(const double newstartingprice);
//	
//	void setInterestRate(const double newinterestrate);
//	
//	void setVolatility(const double newvolatility);
//	
//	void setStrikePrice(const double newstrikeprice);
//	
//	void setStrikeTime(const double newstriketime);
//	
//	void setTimeStepSize(const double newtimestepsize);
//	
//	void setRandomMean(const double newmean);
//	
//	void setStandardDeviation(const double newstandarddeviation);
//	
//	void setNumberOfSimulations(const int newnumberofsimulations);
//
//	void setPrices(const std::vector<double>& newprices);
//	
//	
//    /*---------------------------------------------------------------------------------------------*/
//	/*forward declarations for "getters for the variables"*/
//	double getStartingPrice();
//	
//	double getInterestRate();
//	
//	double getVolatility();
//	
//	double getStrikePrice();
//	
//	double getStrikeTime();
//	
//	double getTimeStepSize();
//	
//	double getRandomMean();
//	
//	double getStandardDeviation();
//	
//	int getNumberOfSimulations();
//
//	std::vector<double> getPrices();
//
//
//    /*---------------------------------------------------------------------------------------------*/
//	/*forward declarations for functions*/
//	void VectorIntialisation(std::vector<double>& prices, int sims, double price);
//
//	//void MonteCarlo();
//
//	//void simd128MonteCarlo();
//
//	//void MonteCarloAuto();
//
//	//void simd128MonteCarloAuto();
//
//	//void simd256MonteCarloAuto();
//
//	double OptionValue(double sumoptionvalue);
//
//	double PutValueCalc(std::vector<double>& vector);
//
//	double CallValueCalc(std::vector<double>& vector);
//
//	double PutValueError(std::vector<double>& vector);
//
//	double CallValueError(std::vector<double>& vector);
//
//	void PutValue(const std::unique_ptr<Contract>& obj);
//
//	void CallValue(const std::unique_ptr<Contract>& obj);
//
//	void AverageStrikePrice(const std::unique_ptr<Contract>& obj);
//
//	void Variables();
//};
//#endif
