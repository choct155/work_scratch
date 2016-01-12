*Read in simulated data;
proc import datafile="C:\cygwin64\home\MarvinW\work_scratch\stata_test_data.csv"
	out=test
	dbms=csv
	replace;
run;

*Estimate multivariate probit model;
proc qlim data=test method=qn outest=mod_est covout;
	model y1=x1;
	model y2=x1 x2;
	model y3 = x1 x2 x3;
	model y4=x1 x2 x3 x4;
	endogenous y1 y2 y3 y4 ~ discrete;
	output out=mod_out marginal predicted prob;
run;

*Inspect results output;
data mod_est;
	set mod_est;
run;
data mod_out;
	set mod_out;
run;

*Write model estimates and output to disk;
proc export data=mod_est
	outfile="C:\cygwin64\home\MarvinW\work_scratch\mod_est.csv"
	dbms=CSV
	replace;
run;
proc export data=mod_out
	outfile="C:\cygwin64\home\MarvinW\work_scratch\mod_out.csv"
	dbms=CSV
	replace;
run;