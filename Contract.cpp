#include "Contract.h"

/*-------------------------------------------------------------------------------------------------*/
/*constructor and destructor for an object of this class*/

Contract::Contract(double startingprice, double interestrate, double volatility,
	double strikeprice, double striketime, double timestepsize,
	double randommean, double standarddeviation, int numberofsimulations, double drift) :

	StartingPrice(startingprice),

	InterestRate(interestrate),

	Volatility(volatility),

	StrikePrice(strikeprice),

	StrikeTime(striketime),

	TimeStepSize(timestepsize),

	RandomMean(randommean),

	StandardDeviation(standarddeviation),

	NumberOfSimulations(numberofsimulations)
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

/*destructor for an object of this class*/
Contract::~Contract()
{

}


/*-------------------------------------------------------------------------------------------------*/
/*sanity check functions*/
void Contract::SanityCheckStartingPrice()
{
	bool check{ false };
	while (!(check == true))
	{
		/*checking that the input is a double*/
		int type_check_sum{ 0 };

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			StartingPrice = 0;
		}

		else
		{
			type_check_sum += 1;
		}

		/*checking the inout is greater than 0*/
		if (StartingPrice <= 0)
		{
			std::cout << "Starting price must be a number greater than " << char(156) << "0.00\n";
			std::cout << "Please enter a starting price: " << std::endl;
			double newstartprice{};
			std::cin >> newstartprice;
			StartingPrice = newstartprice;
		}

		else
		{
			type_check_sum += 1;
		}

		if (type_check_sum == 2)
		{
			check = true;
		}
	}
	VectorIntialisation(*prices, getNumberOfSimulations(), getStartingPrice());
	VectorIntialisation(*averagepersim, getNumberOfSimulations(), 0);
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
			InterestRate = newinterestrate;

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
			Volatility = newvolatility;

		}
	}
}

void Contract::SanityCheckStrikePrice()
{
	bool check{ false };
	while (!(check == true))
	{
		/*checking that the input is a double*/
		int type_check_sum{ 0 };

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			StrikePrice = 0;
		}

		else
		{
			type_check_sum += 1;
		}

		/*checking the inout is greater than 0*/
		if (StrikePrice <= 0)
		{
			std::cout << "Strike price must be a number greater than " << char(156) << "0.00\n";
			std::cout << "Please enter a strike price: " << std::endl;
			double newstrikeprice{};
			std::cin >> newstrikeprice;
			StrikePrice = newstrikeprice;
		}

		else
		{
			type_check_sum += 1;
		}

		if (type_check_sum == 2)
		{
			check = true;
		}
	}
}

void Contract::SanityCheckStrikeTime()
{
	bool check{ false };
	while (!(check == true))
	{
		/*checking that the input is a double*/
		int type_check_sum{ 0 };

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			StartingPrice = 0;
		}

		else
		{
			type_check_sum += 1;
		}

		/*checking the inout is greater than 0*/
		if (StrikeTime <= 0)
		{
			std::cout << "Strike time must be a number greater than " << "0.00\n";
			std::cout << "Please enter a strike time: " << std::endl;
			double newstriketime{};
			std::cin >> newstriketime;
			StrikeTime = newstriketime;
		}

		else
		{
			type_check_sum += 1;
		}

		if (type_check_sum == 2)
		{
			check = true;
		}
	}
}

void Contract::SanityCheckTimeStepSize()
{
	bool check{ false };
	while (!(check == true))
	{
		/*checking that the input is a double*/
		int type_check_sum{ 0 };

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			TimeStepSize = 0;
		}

		else
		{
			type_check_sum += 1;
		}

		/*checking the inout is greater than 0*/
		if (TimeStepSize <= 0)
		{
			std::cout << "Time step size must be a number greater than " << "0.00\n";
			std::cout << "Please enter a time step size: " << std::endl;
			double newtimestepsize{};
			std::cin >> newtimestepsize;
			TimeStepSize = newtimestepsize;
		}

		else
		{
			type_check_sum += 1;
		}

		if (type_check_sum == 2)
		{
			check = true;
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

void Contract::SanityCheckDrift()
{
	/*checking that the input is a double*/
	if (std::cin.fail()) {
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Drift must be a number\n";
			std::cout << "Please enter a drift percentage: " << std::endl;
			double newdrift{};
			std::cin >> newdrift;
			setDrift(newdrift);

		}
	}
}

void Contract::SanityCheckStandardDeviation()
{
	bool check{ false };
	while (!(check == true))
	{
		/*checking that the input is a double*/
		int type_check_sum{ 0 };

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			StartingPrice = 0;
		}

		else
		{
			type_check_sum += 1;
		}

		/*checking the inout is greater than 0*/
		if (StandardDeviation <= 0)
		{
			std::cout << "Standard deviation must be a number greater than " << "0.00\n";
			std::cout << "Please enter a standard deviation: " << std::endl;
			double newstandarddeviation{};
			std::cin >> newstandarddeviation;
			StandardDeviation = newstandarddeviation;
		}

		else
		{
			type_check_sum += 1;
		}

		if (type_check_sum == 2)
		{
			check = true;
		}
	}
}

void Contract::SanityCheckNumberOfSimulations()
{
	bool check{ false };
	while (!(check == true))
	{
		/*checking that the input is a double*/
		int type_check_sum{ 0 };

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			StartingPrice = 0;
		}

		else
		{
			type_check_sum += 1;
		}

		/*checking the inout is greater than 0*/
		if (StartingPrice <= 0)
		{
			std::cout << "Number of simulations must be a number greater than " << "0.00\n";
			std::cout << "Please enter number of simulations: " << std::endl;
			double newnumberofsimulations{};
			std::cin >> newnumberofsimulations;
			NumberOfSimulations = newnumberofsimulations;
		}

		else
		{
			type_check_sum += 1;
		}

		if (type_check_sum == 2)
		{
			check = true;
		}
	}
	VectorIntialisation(*prices, getNumberOfSimulations(), getStartingPrice());
	VectorIntialisation(*averagepersim, getNumberOfSimulations(),0);
}


/*-------------------------------------------------------------------------------------------------*/
/*setters for private variables within this class*/

void Contract::setStartingPrice(const double newstartingprice)
{
	StartingPrice = newstartingprice;

	SanityCheckStartingPrice();
}

void Contract::setInterestRate(const double newinterestrate)
{
	InterestRate = newinterestrate;

	SanityCheckInterestRate();
}

void Contract::setVolatility(const double newvolatility)
{
	Volatility = newvolatility;

	SanityCheckVolatility();
}

void Contract::setStrikePrice(const double newstrikeprice)
{
	StrikePrice = newstrikeprice;

	SanityCheckStartingPrice();
}

void Contract::setStrikeTime(const double newstriketime)
{
	StrikeTime = newstriketime;

	SanityCheckStrikeTime();
}

void Contract::setTimeStepSize(const double newtimestepsize)
{
	TimeStepSize = newtimestepsize;

	SanityCheckTimeStepSize();
}

void Contract::setRandomMean(const double newmean)
{
	RandomMean = newmean;

	SanityCheckRandomMean();
}

void Contract::setStandardDeviation(const double newstandarddeviation)
{
	StandardDeviation = newstandarddeviation;

	SanityCheckStandardDeviation();
}

void Contract::setNumberOfSimulations(const int newnumberofsimulations)
{
	NumberOfSimulations = newnumberofsimulations;

	SanityCheckNumberOfSimulations();

}

void Contract::setPrices(const std::vector<double>& newprices)
{
	delete prices;
	prices = new std::vector<double>{ newprices };
}

void Contract::setAveragePerSim(const std::vector<double>& newprices)
{
	delete averagepersim;
	averagepersim = new std::vector<double>{ newprices };
}

void Contract::setDrift(const double newdrift)
{
	Drift = newdrift;

	SanityCheckDrift();
}
/*-------------------------------------------------------------------------------------------------*/
/*getters for private variables within this class*/

double Contract::getStartingPrice()
{
	return StartingPrice;
}

double Contract::getInterestRate()
{
	return InterestRate;
}

double Contract::getVolatility()
{
	return Volatility;
}

double Contract::getStrikePrice()
{
	return StrikePrice;
}

double Contract::getStrikeTime()
{
	return StrikeTime;
}

double Contract::getTimeStepSize()
{
	return TimeStepSize;
}

double Contract::getRandomMean()
{
	return RandomMean;
}

double Contract::getStandardDeviation()
{
	return StandardDeviation;
}

int Contract::getNumberOfSimulations()
{
	return NumberOfSimulations;
}

std::vector<double> Contract::getPrices()
{
	return *prices;
}

std::vector<double> Contract::getAveragePerSim()
{
	return *averagepersim;
}

double Contract::getDrift()
{
	return Drift;
}

/*-------------------------------------------------------------------------------------------------*/
/*functions for all contract class, excluding getters and setters*/

/*intialises the price vector with the startting price with the required number of simulations*/
void Contract::VectorIntialisation(std::vector<double>& vector, int vectorlength,
	double elementvalue)
{
	vector.assign(vectorlength, elementvalue);
}

/*prints the average price of the assest at the strike time with its associated errors*/
void Contract::AverageStrikePrice()
{
	
	std::cout << "Average assest price at strike time :" << char(156) << Mean(getPrices()) 
		<< "    ( +- " << StDev(getPrices())*1.96 <<" )\n\n";
}

/*prints all the inputted variables used in the class*/
void Contract::Variables()
{
	std::cout << "Initial price: " << char(156) << getStartingPrice() << "\n\n";
	std::cout << "Strike price: " << char(156) << getStrikePrice() << "\n\n";
	std::cout << "Volatility: " << getVolatility() << "\n\n";
	std::cout << "Interest rate: " << getInterestRate() << "\n\n";
	std::cout << "Strike time: " << getStrikeTime() << " years\n\n";
	std::cout << "Time step size: " << getTimeStepSize() << " years\n\n";
}


/*-------------------------------------------------------------------------------------------------*/
/*Base case functions for the european class to override. If not overriden then presnt the 
user with a message saying the function is not usable with the selected contract class and
exit the program*/

void Contract::PutValue()
{
	std::cout << "PutValue() function does not work with the chosen contract type of \""
		<< typeid(*this).name() <<"\"\n";
	exit(0);
}

void Contract::CallValue()
{
	std::cout << "CallValue() function does not work with the chosen contract type of \""
		<< typeid(*this).name() << "\"\n";
	exit(0);
}

/*-------------------------------------------------------------------------------------------------*/
/*Base case functions for the asian class to override if not overriden then present the
user with a message saying the function is not usable with the selected contract class and 
exit the program*/

void Contract::Value()
{
	std::cout << "PutValue() function does not work with the chosen contract type of \""
		<< typeid(*this).name() << "\"\n";
	exit(0);
}