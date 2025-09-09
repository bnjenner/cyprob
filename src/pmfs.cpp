#include <cmath>
#include <boost/math/special_functions/log1p.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include "definitions.h"
#include "basic_ops.h"
#include "pmfs.h"


// Binomial PMF
double binomial_pmf(const int &k, const int &n, const float &p) {
	/*
		Not optimized to handle infinite precision, so expect some rounding errors.
	*/
	boost_float res = static_cast<boost_float>(comb(n, k));
	boost_float bp = p;
	boost_float bq = 1 - p;
	for (int i = 0; i < k; i++) { res *= bp; }
	for (int i = 0; i < (n - k); i++) { res *= bq; }
	return res.convert_to<double>();	
}
