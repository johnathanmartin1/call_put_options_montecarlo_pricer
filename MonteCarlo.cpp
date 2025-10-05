#include "MonteCarlo.h"

/*running the random walk at each time step for each element in the price array*/
/*rterwrite to makle it more simd compatible*/
void MonteCarlo::RandomWalk(const std::unique_ptr<Contract>& obj)
{
	std::vector<double> results(obj->getPrices().size());
	results = obj->getPrices();
	std::vector<double> average(obj->getAveragePerSim().size(),0);
	/*looping through each simulation held in vector*/
	//applying theparralell processing to the loop
	std::random_device r; //settig a random seed

	std::default_random_engine generator(r()); //random generator from the random seed

	std::normal_distribution<double> distribution(obj->getRandomMean(), obj->getStandardDeviation());
	std::vector<double> randvec(obj->getPrices().size());
	for (double t = 0; t <= obj->getStrikeTime(); t += obj->getTimeStepSize())
	{	
		for (int i = 0; i < obj->getPrices().size(); i++)
		{
			randvec[i] = distribution(generator);
		}
		/*updating vector at each time step with black scholes log random walk*/
		for (int i = 0; i < obj->getNumberOfSimulations(); ++i)
		{
			double result = BlackScholes(results[i], obj, randvec[i]);
			results[i] = result;
			average[i] += result;
		}
	}
	for (double& element : average)
	{
		element /= obj->getStrikeTime()/obj->getTimeStepSize();
	}
	obj->setAveragePerSim(average);
	obj->setPrices(results);
}






/*This function (random walk) could be made into a mutilthreaded operation as each element in
the array is independent from another, this would increase speed*/
double MonteCarlo::BlackScholes(double currentprice, const std::unique_ptr<Contract>& obj, 
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

/*this function determines the number of monte carlo simulations required for a 95% confidence
window i.e. the result of th eavergae price at strike time will be within £0.01 of each other on 
each independent run*/
int MonteCarlo::NumberOfRuns(const std::unique_ptr<Contract>& obj)
{
	double StdDev{};
	StdDev = StDev(obj->getPrices());
	int runs{};
	runs = std::pow(1.96 * StdDev / 0.01, 2);
	return runs;
}



void MonteCarlo::simd128RandomWalk(const std::unique_ptr<Contract>& obj)
{
	std::vector<double> results(obj->getPrices().size());
	
	results = obj->getPrices();
	
	std::vector<double> average(obj->getAveragePerSim().size());
	
	std::random_device r; //settig a random seed

	std::mt19937 generator(r()); //random generator from the random seed

	std::normal_distribution<double> distribution(obj->getRandomMean(), obj->getStandardDeviation());
	
	std::vector<double> randvec(obj->getPrices().size());
	for (double t = 0; t <= obj->getStrikeTime(); t += obj->getTimeStepSize())
	{
		
		for (int i=0; i<randvec.size(); ++i)
		{
			randvec[i] = distribution(generator);
		}

		
		std::vector<double> result = simd128BlackScholes(results, obj, randvec);
		results = result;
		for (int i = 0; i < average.size(); i += 2) 
		{
			__m128d av = _mm_load_pd(average.data() + i);
			__m128d result_av =  _mm_load_pd(result.data()+i);
			__m128d res = _mm_add_pd(av, result_av);
			_mm_store_pd(average.data() + i, res);
		}
	}

	for (int i=0; i<average.size();i+=2)
	{
		__m128d av_container = _mm_load_pd(average.data() + i);
		__m128d len = _mm_set1_pd(obj->getStrikeTime()/obj->getTimeStepSize());
		
		__m128d av_result = _mm_div_pd(av_container, len);
		_mm_store_pd(average.data() + i, av_result);
	}
	
	obj->setAveragePerSim(average);
	obj->setPrices(results);
}


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
/*128 bit simd verion of the black scholes calculation limited to 2 doubles calcs per thread*/
 std::vector<double> MonteCarlo::simd128BlackScholes(
	const std::vector<double>& currentprice, const std::unique_ptr<Contract>& obj, 
	const std::vector<double>& randomnumber)
{
	std::vector<double> results(currentprice.size());
	
	for (int i = 0; i < currentprice.size(); i += 2)
	{	
		__m128d rand = _mm_load_pd(randomnumber.data()+i);
	
		__m128d half = _mm_set1_pd(0.5);
		
		__m128d vol = _mm_set1_pd(obj->getVolatility());
		
		__m128d interest = _mm_set1_pd(obj->getInterestRate());
		
		__m128d timer = _mm_set1_pd(obj->getTimeStepSize());
		
		__m128d curprice = _mm_load_pd(currentprice.data()+i);

		/*calculate the black scholes formula*/
        __m128d result = _mm_mul_pd(curprice, _mm_exp_pd(_mm_add_pd(
			_mm_mul_pd(_mm_sub_pd(interest, _mm_mul_pd(
				half, _mm_mul_pd(vol, vol))), timer),
					_mm_mul_pd(_mm_mul_pd(vol, _mm_sqrt_pd(timer)), rand))));
		
		/*store the calculations in the results vector which can then be passed onto the
		prices vector to be reused for the next time step*/
		
		_mm_store_pd(results.data()+i, result);
	}
	
	return  results;
}


void MonteCarlo::AutoPrecisionRandomWalk(const std::unique_ptr<Contract>& obj)
{
	simd128RandomWalk(obj);
	
	obj->setNumberOfSimulations(NumberOfRuns(obj));
	
	std::vector<double> newav(obj->getNumberOfSimulations(), 0);
	
	obj->setAveragePerSim(newav);
	
	std::cout << "The number of runs needed for 0.01 precision on average is " <<
		obj->getNumberOfSimulations() << "\n\n";
	
	simd128RandomWalk(obj);
}
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

