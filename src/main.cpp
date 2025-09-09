#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <boost/multiprecision/cpp_int.hpp>
#include "conversions.h"

namespace py = pybind11;
using boost_int = boost::multiprecision::cpp_int;

// Factorial
boost_int fact(const int a) {
	if (a == 0) { return 1; }
	boost_int res = 1;
	for (int i = 2; i <= a; i++) {
		res *= i;
	}
	return res;
}

// Permutation
boost_int perm(const int n, const int k) {
	if (k > n) { return 0; }
	if (k == 0) { return 1; }
	boost_int res = 1;
	for (int i = 0; i < k; i++) {
		res *= n-i;
	}
	return res;
}

// Combination
boost_int comb(const int n, int k) {
	if (k > n) { return 0; }
	if (k == 0) { return 1; } 
	if (k > n - k) k = n - k; // Pascal's triangle
	boost_int res = 1;
	for (int i = 0; i < k; i++) {
		res *= n-i;
		res /= i+1;
	}
	return res;
}

// // Binomial PMF
// long double binomial_pmf(const int &k, const int &n, const float &p) {
// 	long double res = comb(n, k);
// 	for (int i = 0; i < k; i++) { res *= p; }
// 	for (int i = 0; i < (n - k); i++) { res *= 1-p; }
// 	return res;	
// }

// pybind11 module definition
PYBIND11_MODULE(cyprob, handle) {
    handle.doc() = "Probability and Statistics related functions implemented in C++."; // optional module docstring
    handle.def("fact", 
    		   [](const int a) {
			        return py::cast(fact(a)); 
				}, 
			   "Takes factorial of an integer. Returns integer.");
    handle.def("perm", 
    		   [](const int n, const int k) {
			        return py::cast(perm(n, k)); 
				}, 
			   "Calculates k permutations of N. Returns integer.");
    handle.def("comb", 
    		   [](const int n, const int k) {
			        return py::cast(comb(n, k)); 
				}, 
			   "Calculates k combinations of N. Returns combinations.");
	// handle.def("binomial_pmf", &binomial_pmf, "Calculates the probability of an outcome for the Binomal Distribution. Returns float.");
}