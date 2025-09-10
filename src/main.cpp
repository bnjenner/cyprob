#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "definitions.h"
#include "conversions.h"
#include "basic_ops.h"
#include "pmfs.h"


// pybind11 module definition
PYBIND11_MODULE(cyprob, handle) {
    handle.doc() = "Probability and Statistics related functions implemented in C++."; // optional module docstring
    handle.def("fact", 
    		   [](const int a) {
			        return pybind11::cast(fact(a)); 
				}, 
			   "Takes factorial of an integer. Returns integer.");
    handle.def("perm", 
    		   [](const int n, const int k) {
			        return pybind11::cast(perm(n, k)); 
				}, 
			   "Calculates k permutations of N. Returns integer.");
    handle.def("comb", 
    		   [](const int n, const int k) {
			        return pybind11::cast(comb(n, k)); 
				}, 
			   "Calculates k combinations of N. Returns combinations.");
	handle.def("binomial_pmf", &binomial_pmf, "Calculates the probability of an outcome for the Binomal Distribution. Returns float.");
	handle.def("poisson_pmf", &poisson_pmf, "Calculates the probability of an outcome for the Poisson Distribution. Returns float.");

}