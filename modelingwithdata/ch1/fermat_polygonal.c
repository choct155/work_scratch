/*This program tests Fermat's polygonal number theorem for all 
numbers in the [1,100] interval*/

#include <stdio.h>

//Define function to generate a triangular number
int triangular(int i){

	//Define triangular sum
	int tsum=0;

	//Define iterator
	int j;

	//Calculate triangular sum up to i
	for (j=1; j<i+1; j++){
		tsum+=j;
	}

	return tsum;
}

//Define function identifying the triangular number following the input triangular
int find_next_triangular(int in){

	//Define triangular sum
	int tsum_test=0;

	//Define iterator
	int j;

	//Define iterator
	j=0;

	//Identify the integer used to calculate the input triangular
	while (tsum_test<in){
		//printf("Input tri: %d\n", in);
		//printf("Test tri: %d\n", tsum_test);
		//printf("Index: %d\n", j);
		tsum_test+=j;
		j++;
	}

	//Return the next triangular number
	return j;
}

//Define function that captures three or less triangular numbers that sum to the input
void find_triplet(int in, int out[]){

	int max_idx; //index of largest possible triangular number portion of input
	int i,j,k; //iterators

	//Find largest possible index for one of the sum components
	max_idx=find_next_triangular(in)-1;

	//If the input was a triangular number, we are done
	if (triangular(max_idx)==in){
		printf("The input was triangular!\n");
	}
	else{
		for (i=0; i<=max_idx; i++){
			for (j=0; j<=max_idx; j++){
				for (k=0;k<max_idx; k++){
					if (i+j+k==in){
						out[0]=i;
						out[1]=j;
						out[2]=k;
						return;
					}
				}
			}
		}
	}
}

void main(){
	int idx=5;
	int decomp=30;
	int out_sum[3];
	printf("The triangular number in position %d is %d.\n",idx,triangular(idx));
	printf("The index position of the next triangular number is %d.\n",find_next_triangular(triangular(idx)));
	find_triplet(decomp,out_sum);
	printf("The triangular numbers that sum to %d are %d, %d, and %d.\n",decomp,out_sum[0],out_sum[1],out_sum[2]);
}

