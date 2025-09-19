#include "Option.h"

/*-------------------------------------------------------------------------------------------------*/
/*constructor for an objecty of this class*/

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
	SanityCheckStartingPrice();

	SanityCheckInterestRate();

	SanityCheckVolatility();

	SanityCheckStrikePrice();

	SanityCheckStrikeTime();

	SanityCheckTimeStepSize();
	
	SanityCheckRandomMean();

	SanityCheckStandardDeviation();
	
	SanityCheckNumberOfSimulations();
};

/*-------------------------------------------------------------------------------------------------*/
/*sanity check functions*/
void Contract::SanityCheckStartingPrice() 
{
	/*checking that the input is a double*/
	if (std::cin.fail()) {
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Starting price must be a number greater than " << char(156) << "0.00\n";
			std::cout << "Please enter a starting price: " << std::endl;
			double newstartprice{};
			std::cin >> newstartprice;
			setStartingPrice(newstartprice);

		}
	}
	else {
		/*checking the inout is greater than 0*/
		while (*StartingPrice <= 0)
		{
			std::cerr << "Starting price must be a number greater than " << char(156) << "0.00\n";
			std::cout << "Please enter a starting price: " << std::endl;
			double newstartprice{};
			std::cin >> newstartprice;
			setStartingPrice(newstartprice);
			setStartingPrice(newstartprice);
		}
	}
	VectorIntialisation(prices, getNumberOfSimulations(), getStartingPrice());
}

void Contract::SanityCheckInterestRate() 
{
	if (std::cin.fail()) {
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Intertest rate must be a number\n";
			std::cout << "Please enter an interest rate: " << std::endl;
			double newinterestrate{};
			std::cin >> newinterestrate;
			setInterestRate(newinterestrate);

		}
	}
}

void Contract::SanityCheckVolatility()
{
	if (std::cin.fail()) {
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Volatility must be a number\n";
			std::cout << "Please enter a volatility: " << std::endl;
			double newvolatility{};
			std::cin >> newvolatility;
			setVolatility(newvolatility);

		}
	}
}

void Contract::SanityCheckStrikePrice()
{
	/*checking that the input is a double*/
	if (std::cin.fail()) {
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Strike price must be a number greater than " << char(156) << "0.00\n";
			std::cout << "Please enter a strike price: " << std::endl;
			double newstrikeprice{};
			std::cin >> newstrikeprice;
			setStrikePrice(newstrikeprice);

		}
	}
	else {
		/*checking the inout is greater than 0*/
		while (*StrikePrice <= 0)
		{
			std::cerr << "Strike price must be a number greater than " << char(156) << "0.00\n";
			std::cout << "Please enter a strike price: " << std::endl;
			double newstrikeprice{};
			std::cin >> newstrikeprice;
			setStrikePrice(newstrikeprice);
			setStrikePrice(newstrikeprice);
		}
	}
	
}

void Contract::SanityCheckStrikeTime()
{
	/*checking that the input is a double*/
	if (std::cin.fail()) {
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Strike time must be a number greater than " << "0.00\n";
			std::cout << "Please enter a strike time: " << std::endl;
			double newstriketime{};
			std::cin >> newstriketime;
			setStrikeTime(newstriketime);
		}
	}
	else {
		/*checking the inout is greater than 0*/
		while (*StrikeTime <= 0)
		{
			std::cerr << "Strike time must be a number greater than " <<  "0.00\n";
			std::cout << "Please enter a strike time: " << std::endl;
			double newstriketime{};
			std::cin >> newstriketime;
			setStrikeTime(newstriketime);
			setStrikeTime(newstriketime);
		}
	}
}

void Contract::SanityCheckTimeStepSize()
{
	/*checking that the input is a double*/
	if (std::cin.fail()) {
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Time step size must be a number greater than " << "0.00\n";
			std::cout << "Please enter a time step size: " << std::endl;
			double newtimestepsize{};
			std::cin >> newtimestepsize;
			setTimeStepSize(newtimestepsize);

		}
	}
	else {
		/*checking the inout is greater than 0*/
		while (*TimeStepSize <= 0)
		{
			std::cerr << "Time step size must be a number greater than " << "0.00\n";
			std::cout << "Please enter a time step size: " << std::endl;
			double newtimestepsize{};
			std::cin >> newtimestepsize;
			setTimeStepSize(newtimestepsize);
			setTimeStepSize(newtimestepsize);
		}
	}
}

void Contract::SanityCheckRandomMean()
{
	/*checking that the input is a double*/
	if (std::cin.fail()) {
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Random walk mean size must be a number\n";
			std::cout << "Please enter a random walk mean: " << std::endl;
			double newrandomwalkmean{};
			std::cin >> newrandomwalkmean;
			setRandomMean(newrandomwalkmean);

		}
	}
}

void Contract::SanityCheckStandardDeviation()
{
	/*checking that the input is a double*/
	if (std::cin.fail()) {
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Random walk standard deviation must be a number greater than " << "0.00\n";
			std::cout << "Please enter a random walk standard deviation: " << std::endl;
			double newstandarddeviation{};
			std::cin >> newstandarddeviation;
			setStandardDeviation(newstandarddeviation);

		}
	}
	else {
		/*checking the inout is greater than 0*/
		while (*StandardDeviation <= 0)
		{
			std::cerr << "Random walk standard deviation must be a number greater than " << "0.00\n";
			std::cout << "Please enter a random walk standard deviation: " << std::endl;
			double newstandarddeviation{};
			std::cin >> newstandarddeviation;
			setStandardDeviation(newstandarddeviation);
			setStandardDeviation(newstandarddeviation);
		}
	}
}

void Contract::SanityCheckNumberOfSimulations()
{
	/*checking that the input is a double*/
	if (std::cin.fail()) {
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Number of simulations must be an integer greater than " << "0\n";
			std::cout << "Please enter the number of simulations: " << std::endl;
			double newsims{};
			std::cin >> newsims;
			setNumberOfSimulations(newsims);

		}
	}
	else {
		/*checking the inout is greater than 0*/
		while (*NumberOfSimulations <= 0)
		{
			std::cerr << "Number of simulations must be an integer greater than " << "0\n";
			std::cout << "Please enter the number of simulations: " << std::endl;
			double newsims{};
			std::cin >> newsims;
			setNumberOfSimulations(newsims);
			setNumberOfSimulations(newsims);
		}
	}
	VectorIntialisation(prices, getNumberOfSimulations(), getStartingPrice());
}


/*-------------------------------------------------------------------------------------------------*/
/*setters for private variables within this class*/

void Contract::setStartingPrice(double newstartingprice) 
{
	StartingPrice = std::move(std::make_unique<double>(newstartingprice));

	SanityCheckStartingPrice();	
}

void Contract::setInterestRate(double newinterestrate) 
{
	InterestRate = std::move(std::make_unique<double>(newinterestrate));

	SanityCheckInterestRate();
}

void Contract::setVolatility(double newvolatility) 
{
	Volatility = std::move(std::make_unique<double>(newvolatility));

	SanityCheckVolatility();
}

void Contract::setStrikePrice(double newstrikeprice) 
{
	StrikePrice = std::move(std::make_unique<double>(newstrikeprice));

	SanityCheckStartingPrice();
}

void Contract::setStrikeTime(double newstriketime) 
{
	StrikeTime = std::move(std::make_unique<double>(newstriketime));

	SanityCheckStrikeTime();
}

void Contract::setTimeStepSize(double newtimestepsize) 
{
	TimeStepSize = std::move(std::make_unique<double>(newtimestepsize));

	SanityCheckTimeStepSize();
}

void Contract::setRandomMean(double newmean) 
{
	RandomMean = std::move(std::make_unique<double>(newmean));

	SanityCheckRandomMean();
}

void Contract::setStandardDeviation(double newstandarddeviation) 
{
	StandardDeviation = std::move(std::make_unique<double>(newstandarddeviation));

	SanityCheckStandardDeviation();
}

void Contract::setNumberOfSimulations(int newnumberofsimulations) 
{
	NumberOfSimulations = std::move(std::make_unique<int>(newnumberofsimulations));
	
	SanityCheckNumberOfSimulations();
	
}


/*-------------------------------------------------------------------------------------------------*/
/*getters for private variables within this class*/

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
/*functions for class, excluding getters and setters*/

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
	setNumberOfSimulations(1000);

	MonteCarlo();
	
	setNumberOfSimulations(NumberOfRuns(prices)); //intialises the vctor with the required number os fims at the starting price
	
	std::cout << "The number of required simulations for " << char(156) <<
		"0.01 accuracy for 95% of runs is " <<
		getNumberOfSimulations() << std::endl;
	
	MonteCarlo();
}

/*Produces the value of a contracts option absed on the call/pit sums of the simulation*/
double Contract::OptionValue(double sumoptionvalue) {
	return (sumoptionvalue / getNumberOfSimulations()) *
		std::exp(-getInterestRate() * getStrikeTime());
}

/*prints the put value of an option with the associated errors*/
void Contract::PutValue()
{
	std::vector<double> priceplus;
	std::vector<double> priceminus;
	double valueerror{};
	valueerror = PutValueError(prices);
	for (double val : prices)
	{
		priceplus.push_back(val + valueerror);
		priceminus.push_back(val - valueerror);
	}
	double uppererror{};
	double lowererror{};
	double averagevalue{};
	uppererror = PutValueCalc(priceplus);
	lowererror = PutValueCalc(priceminus);
	averagevalue = PutValueCalc(prices);
	std::cout << "Put value = " << char(156) << averagevalue << " + " <<
		uppererror - averagevalue << " - " << averagevalue - lowererror << '\n';
}

/*returns the put option value*/
double Contract::PutValueCalc(std::vector<double>& vector)
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
double Contract::PutValueError(std::vector<double>& vector)
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
double Contract::CallValueError(std::vector<double>& vector)
{
	std::vector<double>pricediff;
	for (double i : vector)
	{
		double diff{};
		diff = vector[i] - getStrikePrice();
		if (diff < 0)
		{
			pricediff.push_back(-1*diff);
		}
	}

	double dev = StDev(pricediff);
	return 1.96 * dev;
}

/*prints the call value option wiht its associated errors*/
void Contract::CallValue()
{
	std::vector<double> priceplus;
	std::vector<double> priceminus;
	double valueerror{};
	valueerror = CallValueError(prices);
	for (double val : prices)
	{
		priceplus.push_back(val - valueerror);
		priceminus.push_back(val + valueerror);
	}
	double uppererror{};
	double lowererror{};
	double averagevalue{};
	uppererror = CallValueCalc(priceplus);
	lowererror = CallValueCalc(priceminus);
	averagevalue = CallValueCalc(prices);
	std::cout << "Call value = " << char(156) << averagevalue << " + " <<
		uppererror - averagevalue << " - " << averagevalue - lowererror << '\n';
}

/*returns the call option value*/
double Contract::CallValueCalc(std::vector<double>& vector)
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

/*prints the average price of the assest at the strike time with its associated errors*/
void Contract::AverageStrikePrice()
{
	std::cout << "Average assest price at strike time :" << char(156) << Mean(prices) << " +- "
		<< StDev(prices)*1.96 <<'\n';
}
