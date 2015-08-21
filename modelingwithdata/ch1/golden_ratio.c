/*This program demonstrates convergence to the golden ratio.  It does so by
generating the Fibonacci sequence, and capturing the sequence containing
the nth element over the (n-1)st element.*/

#include <stdio.h>

void main(){

	//Declare variables
	int fib[20];
	double gr[20];
	int i;

	//Initiate Fib sequence
	fib[0]=0;
	fib[1]=1;

	//Generate 20 elements of the Fibonacci sequence
	for (i=2; i<20; i++){
		fib[i]=fib[i-1]+fib[i-2];
	}

	//Initialize golden ratio with arbitrary missing value
	gr[0]=-1.;

	//Generate 19 elements of the sequence converging to the Golden Ratio
	for (i=1; i<20; i++){
		gr[i]=(double) fib[i]/fib[i-1];
	}	

	//Print results
	printf("Fibonacci\tGolden Ratio\n");
	printf("---------\t------------\n");
	for (i=0; i<20; i++){
		printf("%d\t\t%f\n",fib[i],gr[i]);
	}
}