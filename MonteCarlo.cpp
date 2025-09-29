#include "MonteCarlo.h"

/*running the random walk at each time step for each element in the price array*/
/*rterwrite to makle it more simd compatible*/
void RandomWalk(const std::unique_ptr<Contract>& obj)
{
	std::vector<double> results(obj->getPrices().size());
	results = obj->getPrices();
	/*looping through each simulation held in vector*/
	//applying theparralell processing to the loop
	for (double t = 0; t <= obj->getStrikeTime(); t += obj->getTimeStepSize())
	{	
		std::vector<double> rand(obj->getPrices().size());
		rand = RandomVector(obj);
		/*updating vector at each time step with black scholes log random walk*/
		for (int i = 0; i < obj->getNumberOfSimulations(); ++i)
		{
			results[i] = BlackScholes(results[i], obj, rand[i]);
		}
	}
	obj->setPrices(results);
}

/*roduces a vector of random numbers for the black scholes equation*/
std::vector<double> RandomVector(const std::unique_ptr<Contract>& obj) 
{
	//normal random number genrator centered on a goven mean with a given standard deviation
	std::random_device r; //settig a random seed

	std::default_random_engine generator(r()); //random generator from the random seed

	std::normal_distribution<double> distribution(obj->getRandomMean(), obj->getStandardDeviation());

	std::vector<double> randvec(obj->getPrices().size());
	for (int i = 0; i < obj->getPrices().size(); i++)
	{
		randvec[i] = distribution(generator);
	}
	return randvec;
}

/*This function (random walk) could be made into a mutilthreaded operation as each element in
the array is independent from another, this would increase speed*/
double BlackScholes(double currentprice, const std::unique_ptr<Contract>& obj, 
	const double randomnumber)
{
	/*calculating the interest component of the assest price*/
	double interest_component{};

	interest_component = (obj->getInterestRate() - 0.5 * std::pow(obj->getVolatility(), 2)) *
		obj->getTimeStepSize();

	/*calculating the random component of the price*/
	double random_component{};

	random_component = obj->getVolatility() * std::sqrt(obj->getTimeStepSize()) * randomnumber;

	/*returning the updated assest price*/
	return currentprice * std::exp(interest_component + random_component);
}

///*this function determines the number of monte carlo simulations required for a 95% confidence
//window i.e. the result of th eavergae price at strike time will be within £0.01 of each other on 
//each independent run*/
//int MonteCarlo::NumberOfRuns(std::vector<double>& vector) {
//	double StdDev{};
//	StdDev = StDev(vector);
//	int runs{};
//	runs = std::pow(1.96 * StdDev / 0.01, 2);
//	return runs;
//}
//
///*
//interest_component = (interestrate - 0.5 * std::pow(volatility,2)) * timestepsize;
//
//vol**2 = _mm_mul_pd(vol,vol)
//0.5*vol**2=_mm_mul_pd(half,_mm_mul_pd(vol,vol))
//interstrate-0.5*vol**2 = _mm_sub_pd(interest,_mm_mul_pd(half,_mm_mul_pd(vol,vol)))
//(interestrate - 0.5 * std::pow(volatility,2)) * timestepsize = _mm_mul_pd(_mm_sub_pd(interest,_mm_mul_pd(half,_mm_mul_pd(vol,vol))),timer)
//
//random_component = volatility * std::sqrt(timestepsize) * distribution(generator)
//std::sqrt(timestepsize) = _mm_sqrt_pd(timer)
//volatility * std::sqrt(timestepsize) = _mm_mul_pd(vol,_mm_sqrt_pd(timer))
//volatility * std::sqrt(timestepsize) * distribution(generator) = _mm_mul_pd(_mm_mul_pd(vol,_mm_sqrt_pd(timer)),rand)
//
//return currentprice * std::exp(interest_component + random_component)
//interestcompont+random = _mm_add_pd(_mm_mul_pd(_mm_sub_pd(interest,_mm_mul_pd(half,_mm_mul_pd(vol,vol)))*timer), _mm_mul_pd(_mm_mul_pd(vol,_mm_sqrt_pd(timer)),rand))
//std::exp(interest_component + random_component) = _mm_exp_pd(_mm_add_pd(_mm_mul_pd(_mm_sub_pd(interest,_mm_mul_pd(half,_mm_mul_pd(vol,vol))),timer), _mm_mul_pd(_mm_mul_pd(vol,_mm_sqrt_pd(timer)),rand)))
//currentprice * std::exp(interest_component + random_component) = _mm_mul_pd(curprice, _mm_exp_pd(_mm_add_pd(_mm_mul_pd(_mm_sub_pd(interest,_mm_mul_pd(half,_mm_mul_pd(vol,vol))),timer), _mm_mul_pd(_mm_mul_pd(vol,_mm_sqrt_pd(timer)),rand))))
//*/
///*128 bit simd verion of the black scholes calculation limited to 2 doubles calcs per thread*/
//std::vector<double> MonteCarlo::simd128BlackScholes(std::vector<double> currentprice,
//	double interestrate, double volatility, double timestepsize, double mean,
//		double standarddeviation) 
//{
//	std::vector<double> results(currentprice.size());
//	
//	std::random_device r; //settig a random seed
//	
//	std::default_random_engine generator(r()); //random generator form the random seed
//	
//	std::normal_distribution<double> distribution(mean, standarddeviation);
//
//	for (int i = 0; i < currentprice.size(); i += 2)
//	{	
//		__m128d rand = _mm_set1_pd(distribution(generator));
//	
//		__m128d half = _mm_set1_pd(0.5);
//		
//		__m128d vol = _mm_set1_pd(volatility);
//		
//		__m128d interest = _mm_set1_pd(interestrate);
//		
//		__m128d timer = _mm_set1_pd(timestepsize);
//		
//		__m128d curprice = _mm_load_pd(currentprice.data()+i);
//
//		/*calculate the black scholes formula*/
//        __m128d result = _mm_mul_pd(curprice, _mm_exp_pd(_mm_add_pd(
//			_mm_mul_pd(_mm_sub_pd(interest, _mm_mul_pd(
//				half, _mm_mul_pd(vol, vol))), timer),
//					_mm_mul_pd(_mm_mul_pd(vol, _mm_sqrt_pd(timer)), rand))));
//		
//		/*store the calculations in the results vector which can then be passed onto the
//		prices vector to be reused for the next time step*/
//		_mm_store_pd(results.data()+i, result);
//	}
//	return results;
//}
//
///*Same as the 128 bit version but can do 4 double type vector calcs per thread*/
//std::vector<double> MonteCarlo::simd256BlackScholes(std::vector<double> currentprice,
//		double interestrate, double volatility, double timestepsize, double mean,
//			double standarddeviation)
//{
//	std::vector<double> results(currentprice.size());
//	
//	std::random_device r; //settig a random seed
//	
//	std::default_random_engine generator(r()); //random generator form the random seed
//	
//	std::normal_distribution<double> distribution(mean, standarddeviation);
//	
//	/*calculate the black scholes equation*/
//	for (int i = 0; i < currentprice.size(); i += 4)
//	{
//		__m256d rand = _mm256_set1_pd(distribution(generator));
//		
//		__m256d half = _mm256_set1_pd(0.5);
//		
//		__m256d vol = _mm256_set1_pd(volatility);
//		
//		__m256d interest = _mm256_set1_pd(interestrate);
//		
//		__m256d timer = _mm256_set1_pd(timestepsize);
//		
//		__m256d curprice = _mm256_load_pd(currentprice.data() + i);
//
//		/*calculate the resut of the black scholes equation*/
//		__m256d result = _mm256_mul_pd(curprice, _mm256_exp_pd(_mm256_add_pd(
//			_mm256_mul_pd(_mm256_sub_pd(interest, _mm256_mul_pd(
//				half, _mm256_mul_pd(vol, vol))), timer),
//          			_mm256_mul_pd(_mm256_mul_pd(vol, _mm256_sqrt_pd(timer)), rand))));
//		
//		/*store the result in the results vector to be passed back to prices for the 
//		next time iteration*/
//		_mm256_store_pd(results.data() + i, result);
//	}
//	return results;
//}
//

