# cyprob

Python library for probability and statistics using C++, pybind11, and Boost.

Side quest for "Computational Biology: Machine Learning Fundamentals" course at BU meant to gain experience in making python libaries in C++.

## Installation

First things first, install git and conda. For information on how to do that, start here: [Install Conda](https://conda.io/projects/conda/en/latest/user-guide/install/index.html)

This utilizes a conda environment to manage the packages. I found this to be the easist deployment method, but install may take awhile.

Here are the install commands

```
git clone https://github.com/bnjenner/cyprob.git
cd cyprob
conda env create -f environment.yml
conda activate cyprob
```
