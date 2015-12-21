import numpy as np
import pandas as pd
from pandas import Series, DataFrame

import pystan as ps
import scipy.stats as stats

import traceback

print('Defining Stan Code')
coin_code = """
data {
    int<lower=0> n; // number of tosses
    int<lower=0> y; // number of heads
}
transformed data {}
parameters {
    real<lower=0, upper=1> p;
}
transformed parameters {}
model {
    p ~ beta(2, 2);
    y ~ binomial(n, p);
}
generated quantities {}
"""
print('Assigning Data')
coin_dat = {
             'n': 100,
             'y': 61,
            }

print('Fitting model')
try:
	fit = ps.stan(model_code=coin_code, data=coin_dat, iter=1000, chains=1)
except:
	traceback.print_exc()

print("fit: ")
print(fit)