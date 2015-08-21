/*This program generates an array of length 100, and populates it with the square of the index
position.  It also prints the correspondence between index position and array value to standard
out.*/

#include <stdio.h>
#include <math.h>

void main(){

	//Declare variables
	int arr[100];
	int i;

	//For 100 iterations...
	for (i=0; i<100; i++){
		//...populate the array with the square of the counter...
		arr[i]=pow(i,2);
	}
	//printf("%d",arr[10100]);
	//Define function to print out the index/square correspondence
	void print_arr(int in_array[], int array_size){
		//Declare iterator
		int i;
		//Print out all index positions and squares
		for (i=0; i<array_size; i++){
			printf("%d squared is %d\n",i,in_array[i]);	
		}
	}

	//Print out results
	print_arr(arr,100);

	//printf("%d",arr[10100]);

}