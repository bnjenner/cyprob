#include <boost/multiprecision/cpp_int.hpp>
#include "definitions.h"
#include "basic_ops.h"

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