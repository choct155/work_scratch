/*Program switches the values associated with two pointers.  Seems useful for sorting.*/

#include <stdio.h>

void swap(int *p1, int *p2){
	//Declare temporary integer
	int temp;

	//Swap values
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}

void main(){

	//Declare integers
	int first=6;
	int second=9;

	//Print values
	printf("The value of the first integer is %d.\n", first);
	printf("The value of the second integer is %d.\n", second);

	//Swap values
	printf("**PERFORMING SWAP**\n");
	swap(&first,&second);

	//Print values
	printf("Now the value of the first integer is %d.\n", first);
	printf("Now the value of the second integer is %d.\n", second);
}

