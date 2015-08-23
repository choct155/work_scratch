/*This program tests Fermat's polygonal number theorem for all 
numbers in the [1,100] interval */

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
	int tsum_test=in;

	//Define iterator
	int j=0;

	//Identify the integer used to calculate the input triangular
	while (tsum_test>0){
		//printf("Input tri: %d\n", in);
		//printf("Test tri: %d\n", tsum_test);
		//printf("Index: %d\n", j);
		tsum_test-=j;
		j++;
		if (tsum_test-j<0){
			return j;
		}
	}

	//Return the next triangular number
	//return j;
}

//Define function that captures three or less triangular numbers that sum to the input
void find_triplet(int in, int out[]){

	int max_idx; //index of largest possible triangular number portion of input
	int i,j,k; //iterators
	//printf("We must find three or less triangular numbers that sum to %d.\n", in);
	
	//Find largest possible index for one of the sum components
	max_idx=find_next_triangular(in)-1;
	//printf("The largest triangular number possible is %d, which occurs at position %d.\n",triangular(max_idx), max_idx);
	
	//If the input was a triangular number, we are done
	if (triangular(max_idx)==in){
		printf("The input was triangular!\n");
		out[0]=triangular(max_idx);
		return;
	}
	else{ //otherwise loop through all possible index positions to find the combo that adds to the given number
		for (i=0; i<=max_idx; i++){
			for (j=0; j<=max_idx; j++){
				for (k=0;k<max_idx; k++){
					if (triangular(i)+triangular(j)+triangular(k)==in){
						out[0]=triangular(i);
						out[1]=triangular(j);
						out[2]=triangular(k);
						return;
					}
				}
			}
		}
	}
}

void main(){
	//Declare test values for functions
	int idx=6;
	int test_tri=20;
	int decomp=25;

	//Declare array for triplets
	int out_sum[3];

	//Declare iterator
	int i;

	//Print test cases
	printf("The triangular number in position %d is %d.\n",idx,triangular(idx));
	printf("The index position of the next triangular number after %d is %d.\n",test_tri,find_next_triangular(test_tri));
	find_triplet(decomp,out_sum);
	printf("The triangular numbers that sum to %d are %d, %d, and %d.\n",decomp,out_sum[0],out_sum[1],out_sum[2]);

	//Print table headers
	printf("Input\tFirst\tSecond\tThird\n");
	printf("-----\t-----\t------\t-----\n");

	//Find triplets for every number on the [1,100] interval
	for (i=1; i<=100; i++){
		out_sum[0]=0;
		out_sum[1]=0;
		out_sum[2]=0;
		
		find_triplet(i,out_sum);
		printf("%d\t%d\t%d\t%d\n",i,out_sum[0],out_sum[1],out_sum[2]);
	}
}

