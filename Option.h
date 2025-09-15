
#ifndef Contracts
#define Contracts

class Contract {
private:
	std::unique_ptr<double> StartingPrice;
	std::unique_ptr<double> InterestRate;
	std::unique_ptr<double> Volatility;
	std::unique_ptr<double> TimeStepSize;
	std::unique_ptr<double> StrikeTime;
	std::unique_ptr<double> StrikePrice;
	std::unique_ptr<double> Mean;
	std::unique_ptr<double> StandardDeviation;
	std::unique_ptr<int> NumberOfSimulations;
	std::vector<double> prices;

public:
	/*forward declaration for "contract constructor of the variables"*/
	Contract(double startingprice = 100, double interestrate = 0.05, double volatility = 0.2,
		double strikeprice = 115, double striketime = 1, double timestepsize = 0.01,
		double mean = 0, double standarddeviation = 1, int numberofsimulations = 10);
	
	/*forward declaration for "setters for the variables"*/
	void setStartingPrice(double newstartingprice);
	void setInterestRate(double newinterestrate);
	void setVolatility(double newvolatility);
	void setStrikePrice(double newstrikeprice);
	void setStrikeTime(double newstriketime);
	void setTimeStepSize(double newtimestepsize);
	void setMean(double newmean);
	void setStandardDeviation(double newstandarddeviation);
	void setNumberOfSimulations(int newnumberofsimulations);
	
	/*forward declarations for "getters for the variables"*/
	double getStartingPrice();
	double getInterestRate();
	double getVolatility();
	double getStrikePrice();
	double getStrikeTime();
	double getTimeStepSize();
	double getMean();
	double getStandardDeviation();
	int getNumberOfSimulations();

	void VectorIntialisation(std::vector<double>& prices, int sims, double price);
};




#endif
