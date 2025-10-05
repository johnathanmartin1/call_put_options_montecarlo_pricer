//#include "Option.h"
//
///*-------------------------------------------------------------------------------------------------*/
///*constructor for an object of this class*/
//
//Contract::Contract(double startingprice, double interestrate, double volatility,
//	double strikeprice, double striketime, double timestepsize ,
//	double randommean, double standarddeviation, int numberofsimulations) :
//
//	StartingPrice ( startingprice ),
//	
//	InterestRate ( interestrate ),
//	
//	Volatility ( volatility ),
//	
//	StrikePrice ( strikeprice ),
//	
//	StrikeTime ( striketime ),
//	
//	TimeStepSize ( timestepsize ),
//	
//	RandomMean ( randommean ),
//	
//	StandardDeviation ( standarddeviation ),
//	
//	NumberOfSimulations ( numberofsimulations )
//{
//	/*Sanity checks on the input*/
//	SanityCheckStartingPrice();
//
//	SanityCheckInterestRate();
//
//	SanityCheckVolatility();
//
//	SanityCheckStrikePrice();
//
//	SanityCheckStrikeTime();
//
//	SanityCheckTimeStepSize();
//	
//	SanityCheckRandomMean();
//
//	SanityCheckStandardDeviation();
//	
//	SanityCheckNumberOfSimulations();
//};
//
///*destructor for an object of this class*/
//Contract::~Contract()
//{
//	
//}
//
///*-------------------------------------------------------------------------------------------------*/
///*sanity check functions*/
//void Contract::SanityCheckStartingPrice() 
//{
//	bool check{ false };
//	while (!(check == true)) 
//	{
//		/*checking that the input is a double*/
//		int type_check_sum{ 0 };
//	
//		if (std::cin.fail())
//		{
//			std::cin.clear();
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			StartingPrice = 0;
//		}
//		
//		else 
//		{ 
//			type_check_sum += 1; 
//		}
//		
//		/*checking the inout is greater than 0*/
//		if (StartingPrice <= 0)
//		{
//			std::cout << "Starting price must be a number greater than " << char(156) << "0.00\n";
//			std::cout << "Please enter a starting price: " << std::endl;
//			double newstartprice{};
//			std::cin >> newstartprice;
//			StartingPrice = newstartprice;
//		}
//		
//		else
//		{
//			type_check_sum += 1;
//		}
//		
//		if (type_check_sum == 2) 
//		{
//			check = true;
//		}
//	}
//	VectorIntialisation(*prices, getNumberOfSimulations(), getStartingPrice());
//}
//
//void Contract::SanityCheckInterestRate() 
//{
//	if (std::cin.fail()) {
//		while (std::cin.fail())
//		{
//			std::cin.clear();
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			std::cout << "Intertest rate must be a number\n";
//			std::cout << "Please enter an interest rate: " << std::endl;
//			double newinterestrate{};
//			std::cin >> newinterestrate;
//			InterestRate = newinterestrate;
//
//		}
//	}
//}
//
//void Contract::SanityCheckVolatility()
//{
//	if (std::cin.fail()) {
//		while (std::cin.fail())
//		{
//			std::cin.clear();
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			std::cout << "Volatility must be a number\n";
//			std::cout << "Please enter a volatility: " << std::endl;
//			double newvolatility{};
//			std::cin >> newvolatility;
//			Volatility = newvolatility;
//
//		}
//	}
//}
//
//void Contract::SanityCheckStrikePrice()
//{
//	bool check{ false };
//	while (!(check == true))
//	{
//		/*checking that the input is a double*/
//		int type_check_sum{ 0 };
//
//		if (std::cin.fail())
//		{
//			std::cin.clear();
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			StrikePrice = 0;
//		}
//
//		else
//		{
//			type_check_sum += 1;
//		}
//
//		/*checking the inout is greater than 0*/
//		if (StrikePrice <= 0)
//		{
//			std::cout << "Strike price must be a number greater than " << char(156) << "0.00\n";
//			std::cout << "Please enter a strike price: " << std::endl;
//			double newstrikeprice{};
//			std::cin >> newstrikeprice;
//			StrikePrice = newstrikeprice;
//		}
//
//		else
//		{
//			type_check_sum += 1;
//		}
//
//		if (type_check_sum == 2)
//		{
//			check = true;
//		}
//	}
//}
//
//void Contract::SanityCheckStrikeTime()
//{
//	bool check{ false };
//	while (!(check == true))
//	{
//		/*checking that the input is a double*/
//		int type_check_sum{ 0 };
//
//		if (std::cin.fail())
//		{
//			std::cin.clear();
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			StartingPrice = 0;
//		}
//
//		else
//		{
//			type_check_sum += 1;
//		}
//
//		/*checking the inout is greater than 0*/
//		if (StartingPrice <= 0)
//		{
//			std::cout << "Strike time must be a number greater than " << "0.00\n";
//			std::cout << "Please enter a strike time: " << std::endl;
//			double newstriketime{};
//			std::cin >> newstriketime;
//			StrikeTime = newstriketime;
//		}
//
//		else
//		{
//			type_check_sum += 1;
//		}
//
//		if (type_check_sum == 2)
//		{
//			check = true;
//		}
//	}
//}
//
//void Contract::SanityCheckTimeStepSize()
//{
//	bool check{ false };
//	while (!(check == true))
//	{
//		/*checking that the input is a double*/
//		int type_check_sum{ 0 };
//
//		if (std::cin.fail())
//		{
//			std::cin.clear();
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			TimeStepSize = 0;
//		}
//
//		else
//		{
//			type_check_sum += 1;
//		}
//
//		/*checking the inout is greater than 0*/
//		if (TimeStepSize <= 0)
//		{
//			std::cout << "Time step size must be a number greater than " << "0.00\n";
//			std::cout << "Please enter a time step size: " << std::endl;
//			double newtimestepsize{};
//			std::cin >> newtimestepsize;
//			TimeStepSize = newtimestepsize;
//		}
//
//		else
//		{
//			type_check_sum += 1;
//		}
//
//		if (type_check_sum == 2)
//		{
//			check = true;
//		}
//	}
//}
//
//void Contract::SanityCheckRandomMean()
//{
//	/*checking that the input is a double*/
//	if (std::cin.fail()) {
//		while (std::cin.fail())
//		{
//			std::cin.clear();
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			std::cerr << "Random walk mean size must be a number\n";
//			std::cout << "Please enter a random walk mean: " << std::endl;
//			double newrandomwalkmean{};
//			std::cin >> newrandomwalkmean;
//			setRandomMean(newrandomwalkmean);
//
//		}
//	}
//}
//
//void Contract::SanityCheckStandardDeviation()
//{
//	bool check{ false };
//	while (!(check == true))
//	{
//		/*checking that the input is a double*/
//		int type_check_sum{ 0 };
//
//		if (std::cin.fail())
//		{
//			std::cin.clear();
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			StartingPrice = 0;
//		}
//
//		else
//		{
//			type_check_sum += 1;
//		}
//
//		/*checking the inout is greater than 0*/
//		if (StandardDeviation <= 0)
//		{
//			std::cout << "Standard deviation must be a number greater than " << "0.00\n";
//			std::cout << "Please enter a standard deviation: " << std::endl;
//			double newstandarddeviation{};
//			std::cin >> newstandarddeviation;
//			StandardDeviation = newstandarddeviation;
//		}
//
//		else
//		{
//			type_check_sum += 1;
//		}
//
//		if (type_check_sum == 2)
//		{
//			check = true;
//		}
//	}
//}
//
//void Contract::SanityCheckNumberOfSimulations()
//{
//	bool check{ false };
//	while (!(check == true))
//	{
//		/*checking that the input is a double*/
//		int type_check_sum{ 0 };
//
//		if (std::cin.fail())
//		{
//			std::cin.clear();
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			StartingPrice = 0;
//		}
//
//		else
//		{
//			type_check_sum += 1;
//		}
//
//		/*checking the inout is greater than 0*/
//		if (StartingPrice <= 0)
//		{
//			std::cout << "Number of simulations must be a number greater than " << "0.00\n";
//			std::cout << "Please enter number of simulations: " << std::endl;
//			double newnumberofsimulations{};
//			std::cin >> newnumberofsimulations;
//			NumberOfSimulations = newnumberofsimulations;
//		}
//
//		else
//		{
//			type_check_sum += 1;
//		}
//
//		if (type_check_sum == 2)
//		{
//			check = true;
//		}
//	}
//	VectorIntialisation(*prices, getNumberOfSimulations(), getStartingPrice());
//}
//
//
///*-------------------------------------------------------------------------------------------------*/
///*setters for private variables within this class*/
//
//void Contract::setStartingPrice(const double newstartingprice) 
//{
//	StartingPrice = newstartingprice;
//
//	SanityCheckStartingPrice();
//}
//
//void Contract::setInterestRate(const double newinterestrate) 
//{
//	InterestRate = newinterestrate;
//
//	SanityCheckInterestRate();
//}
//
//void Contract::setVolatility(const double newvolatility) 
//{
//	Volatility = newvolatility;
//
//	SanityCheckVolatility();
//}
//
//void Contract::setStrikePrice(const double newstrikeprice) 
//{
//	StrikePrice = newstrikeprice;
//
//	SanityCheckStartingPrice();
//}
//
//void Contract::setStrikeTime(const double newstriketime) 
//{
//	StrikeTime = newstriketime;
//
//	SanityCheckStrikeTime();
//}
//
//void Contract::setTimeStepSize(const double newtimestepsize) 
//{
//	TimeStepSize = newtimestepsize;
//
//	SanityCheckTimeStepSize();
//}
//
//void Contract::setRandomMean(const double newmean) 
//{
//	RandomMean = newmean;
//
//	SanityCheckRandomMean();
//}
//
//void Contract::setStandardDeviation(const double newstandarddeviation) 
//{
//	StandardDeviation = newstandarddeviation;
//
//	SanityCheckStandardDeviation();
//}
//
//void Contract::setNumberOfSimulations(const int newnumberofsimulations) 
//{
//	NumberOfSimulations = newnumberofsimulations;
//	
//	SanityCheckNumberOfSimulations();
//	
//}
//
//void Contract::setPrices(const std::vector<double>& newprices)
//{
//	delete prices;
//	prices = new std::vector<double>{ newprices };
//}
//
//
///*-------------------------------------------------------------------------------------------------*/
///*getters for private variables within this class*/
//
//double Contract::getStartingPrice() 
//{
//	return StartingPrice;
//}
//
//double Contract::getInterestRate() 
//{
//	return InterestRate;
//}
//
//double Contract::getVolatility() 
//{
//	return Volatility;
//}
//
//double Contract::getStrikePrice() 
//{
//	return StrikePrice;
//}
//
//double Contract::getStrikeTime() 
//{
//	return StrikeTime;
//}
//
//double Contract::getTimeStepSize() 
//{
//	return TimeStepSize;
//}
//
//double Contract::getRandomMean() 
//{
//	return RandomMean;
//}
//
//double Contract::getStandardDeviation() 
//{
//	return StandardDeviation;
//}
//
//int Contract::getNumberOfSimulations() 
//{
//	return NumberOfSimulations;
//}
//
//std::vector<double> Contract::getPrices()
//{
//	return *prices;
//}
//
//
///*-------------------------------------------------------------------------------------------------*/
///*functions for class, excluding getters and setters*/
//
///*intialises the price vector with the startting price with the required number of simulations*/
//void Contract::VectorIntialisation(std::vector<double>& prices, int sims, double price)
//{
//	prices.assign(sims, price);
//}

///*runs a monte carlo simulation with the chosen number of runs*/
//void Contract::MonteCarlo() 
//{
//	
//	RandomWalk(*prices, getStrikeTime(), getNumberOfSimulations(), getInterestRate(),
//		getVolatility(), getTimeStepSize(), getRandomMean(), getStandardDeviation());
//}
//
//void Contract::simd128MonteCarlo()
//{
//	for (double t = 0; t < getStrikeTime(); t += getTimeStepSize()) {
//		prices = simd128BlackScholes(prices, getInterestRate(),
//			getVolatility(), getTimeStepSize(), getRandomMean(), getStandardDeviation());
//	}
//}
///*runs a monte carlo simulation with the number of runs required for 95% cofidence interval */
//void Contract::MonteCarloAuto()
//{
//	setNumberOfSimulations(1000);
//
//	MonteCarlo();
//	
//	setNumberOfSimulations(NumberOfRuns(prices)); //intialises the vctor with the required number os fims at the starting price
//	
//	std::cout << "The number of required simulations for " << char(156) <<
//		"0.01 accuracy for 95% of runs is " <<
//		getNumberOfSimulations() <<"\n\n";
//	
//	MonteCarlo();
//}
//
//void Contract::simd128MonteCarloAuto()
//{
//	setNumberOfSimulations(1000);
//
//	for (double t = 0; t < getStrikeTime(); t += getTimeStepSize()) {
//		
//		prices = simd128BlackScholes(prices, getInterestRate(),
//			getVolatility(), getTimeStepSize(), getRandomMean(), getStandardDeviation());
//		
//	}
//	
//	setNumberOfSimulations(NumberOfRuns(prices)); //intialises the vctor with the required number os fims at the starting price
//
//	std::cout << "The number of required simulations for " << char(156) <<
//		"0.01 accuracy for 95% of runs is " <<
//		getNumberOfSimulations() << "\n\n";
//	for (double t = 0; t < getStrikeTime(); t += getTimeStepSize()) {
//
//	prices = simd128BlackScholes(prices, getInterestRate(),
//			getVolatility(), getTimeStepSize(), getRandomMean(), getStandardDeviation());
//	}
//	
//}
//
//void Contract::simd256MonteCarloAuto()
//{
//
//	setNumberOfSimulations(1000);
//
//	for (double t = 0; t < getStrikeTime(); t += getTimeStepSize()) {
//
//		prices = simd256BlackScholes(prices, getInterestRate(),
//			getVolatility(), getTimeStepSize(), getRandomMean(), getStandardDeviation());
//
//	}
//
//	setNumberOfSimulations(NumberOfRuns(prices)); //intialises the vctor with the required number os fims at the starting price
//
//	std::cout << "The number of required simulations for " << char(156) <<
//		"0.01 accuracy for 95% of runs is " <<
//		getNumberOfSimulations() << "\n\n";
//	for (double t = 0; t < getStrikeTime(); t += getTimeStepSize()) {
//
//		prices = simd256BlackScholes(prices, getInterestRate(),
//			getVolatility(), getTimeStepSize(), getRandomMean(), getStandardDeviation());
//	}
//
//}