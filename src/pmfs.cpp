#include <cmath>
#include <boost/math/special_functions/log1p.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include "definitions.h"
#include "basic_ops.h"
#include "pmfs.h"

/*
	Not expected to handle infinite precision, so expect some 
		rounding errors if you're getting really crazy with it.
*/

// Binomial PMF
double binomial_pmf(const int &k, const int &n, const float &p) {
	boost_float res = static_cast<boost_float>(comb(n, k));
	boost_float bp = p;
	boost_float bq = 1 - p;
	for (int i = 0; i < k; i++) { res *= bp; }
	for (int i = 0; i < (n - k); i++) { res *= bq; }
	return res.convert_to<double>();	
}


// Binomial PMF
double poisson_pmf(const int &k, const float &l) {
	boost_float bn = std::exp(-1.0f * l);
	boost_float bk = static_cast<boost_float>(fact(k));
	boost_float res = (static_cast<boost_float>(std::pow(l, k)) * bn) / bk;
	return res.convert_to<double>();	
}
