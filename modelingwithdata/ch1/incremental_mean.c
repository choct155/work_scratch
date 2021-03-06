/*Program calculates the mean of an input array via incremental adjustment*/

#include <stdio.h>
#include <assert.h>

double find_mean(double *in, int length){
	//Ensure the vector is not a null vector
	assert(in != NULL);

	//Ensure the vector has a positive length
	assert(length > 0);

	//Declare mean variable and initialize it to equal the first value in the input vector
	double mean=in[0];

	//Declare a variable to hold the old mean
	double old_mean;

	//Declare iterator
	int i;

	printf("INDEX\tVALUE\t\tMEAN\n");
	printf("-----\t-----\t\t----\n");
	printf("%d\t%f\t%f\n",0,in[0],mean );

	//For each remaining position in the vector
	for (i=1; i < length; i++){
		//Set the old mean
		old_mean=mean;
		//Calculate the new mean based upon the old
		mean = ((i*old_mean)/(i+1)) + (in[i]/(i+1));

		printf("%d\t%f\t%f\n",i,in[i],mean );
	}
}

int main(void){
	//Declare vector
	int vec_len=10;
	double vec[vec_len];

	//Declare iterator
	int i;

	//Populate vector
	for (i=0; i < vec_len; i++){
		vec[i]=i*1.;
	}

	//Calculate a running mean
	find_mean(vec,vec_len);
}