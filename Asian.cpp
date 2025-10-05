#include "Asian.h"
std::vector<double> Asian::Payoff(const std::vector<double>& vector)
{
	std::vector<double> payoff = std::vector<double>(vector.size());
	//std::vector<double> av(getAveragePerSim().size());
	//av = getAveragePerSim();
	
	for (int i=0; i< vector.size();i+=2)
	{
		__m128d av = _mm_load_pd(vector.data() + i);
		__m128d strike = _mm_set1_pd(getStrikePrice());
		__m128d payoff1 = _mm_sub_pd(av, strike);
		__m128d zeros = _mm_set1_pd(0);
		__m128d compare = _mm_cmpgt_pd(payoff1, zeros);
		__m128d mask = _mm_set1_pd(1.0);
		__m128d boolian = _mm_and_pd(compare,mask);
		__m128d result = _mm_mul_pd(boolian, payoff1);
		_mm_store_pd(payoff.data() + i, result);
	}
	
	return payoff;
}

void Asian::Value()
{
	double average{};
	average = Mean(Payoff(getAveragePerSim()));
	double value{};
	value = average * std::exp(-1 * getInterestRate() * getDrift());
	std::cout << "The asian value is " << value << "\n\n";
}