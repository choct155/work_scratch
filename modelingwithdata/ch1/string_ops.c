/*Program demonstrates string manipulation operations*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

void astrncpy(char **base, char *copyme){

	printf("Copying '%s' into a location currently featuring the following string: '%s'\n", copyme,*base);
	printf("The location of our string to be copied (%s) is %d.\n", copyme, &copyme);
	printf("The location of our string to be replaced (%s) is %d.\n", *base, base);

	//Declare string length variable
	int new_len=strlen(copyme);
	printf("Calculating new length for replaced memory allocation (%d).\n",new_len);

	//Reallocate pointer array
	*base=realloc(*base,sizeof(char)*new_len+1);
	printf("Reallocating memory allocation.\n");

	//Copy copyme content to base string location
	strncpy(*base,copyme,new_len);

	printf("The string at location %d is now %s\n", base, *base);
	
}

void main(){

	//Declare iterator
	int i;

	//Generate strings
	char first_lit[]="Fortran?";
	char second[]="Now that's a name I've not heard in a long time.";

	//Convert first string to array (so we can get at the pointer to the strings pointer)
	char **first; //Declare pointer to pointer array that represents the first string
	first=malloc(strlen(first_lit)*sizeof(char)); //Allocate space for the pointer array
	*first=first_lit; //Assign values to the pointer locations

	//Copy copyme into base
	astrncpy(first,second);
}