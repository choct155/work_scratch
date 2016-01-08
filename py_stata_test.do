*Change directory to work_scratch
cd C:\cygwin64\home\MarvinW\work_scratch

*Read in data
insheet using stata_test_data.csv

*Capture parameters from input data in mean estimation table
*(mean works because they are represented as repeated values across obs)
mean seed_in obs_in r_in

*Capture the results in an extractable matrix
matrix b=e(b)

*Assign each parameter to a local scalar for use in the routine
local seed_p=b[1,1]
local obs_p=b[1,2]
local r_p=b[1,3]

*Set random seed and number of obs
set seed `seed_p'
set obs `obs_p'

*Run multivariate probit model
mvprobit (y1=x1) (y2=x1 x2) (y3 = x1 x2 x3) (y4=x1 x2 x3 x4), dr(`r_p')

*Store output
estimates store model

*Write estimates to disk
esttab model using py_stata_test_results.csv

exit, STATA clear
