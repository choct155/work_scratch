#include <stdlib.h>
#include <stdio.h>

void swap(int *p1, int *p2){
	//Declare temporary integer
	int temp;

	//Swap values
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}

int main(){
  int array_length=1000;
  int *squares = malloc (array_length * sizeof(int));
  int i;
    for (i=0; i < array_length; i++)
          squares[i] = i * i;  //Note that unlike single value assignment, the pointer nature of the array is implied

  //Swap values in positions 7 and 8
  swap(&squares[7],&squares[8]);

    printf("INDEX\tVALUE\n");
    printf("-----\t-----\n");
    for (i=0; i<array_length; i++){
    	printf("%d\t%d\n", i, squares[i]);
    }
}
