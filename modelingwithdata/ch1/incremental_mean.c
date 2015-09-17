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

	for (i=0; i < length; i++){
		printf("%d\n",in[i] );
	}

	printf("INDEX\tVALUE\tMEAN\n");
	printf("-----\t-----\t----\n");

	//For each remaining position in the vector
	for (i=1; i < length; i++){
		//Set the old mean
		old_mean=mean;
		//Calculate the new mean based upon the old
		mean = ((i*old_mean)/(i+1)) + (in[i]/(i+1));

		printf("%d\t%d\t%d\n",i,in[i],mean );
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
		vec[i]=i;
		printf("%d\n",i );
	}

	//Calculate a running mean
	find_mean(vec,vec_len);
}