/*Program demonstrates string manipulation operations*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

char* astrcpy(char **base, const char *copyme){

	printf("Copying '%s' into a location currently featuring the following string: '%s'\n", copyme,*base);
	printf("The location of our string to be copied (%s) is %p.\n", copyme, (const void *) copyme);
	printf("The location of our string to be replaced (%s) is %p.\n", *base, base);

	//Declare string length variable
	size_t new_len=strlen(copyme);
	printf("***Calculating new length for replaced memory allocation (%zu).***\n",new_len);

	printf("***Reallocating memory allocation.***\n");
	//Generate temporary character object
	char *tmp;
	//If reallocation is possible...
	if (*tmp=realloc(*base,sizeof(char)*(new_len+1)) != NULL){
		//...assign that block to *base...
		*base=tmp;	
	
		//...and copy copyme content to base string location
		strcpy(*base,copyme);
	}
	printf("The string at location %p is now %s\n", base, *base);
	return tmp;
}
	
int main(void){

	//Declare iterator
	int i;

	//Generate strings
	char first_lit[]="Fortran?";
	char second[]="Now that's a name I've not heard in a long time.";

	//Convert first string to array (so we can get at the pointer to the strings pointer)
	char *first; //Declare pointer to pointer array that represents the first string
	first=malloc((strlen(first_lit)+1)*sizeof(char)); //Allocate space for the pointer array
	strcpy(first,first_lit); //Assign values to the pointer locations

	//Try to copy copyme into base, and if it works print the result to standard out
	printf("***Entering `astrcpy`***\n");
	if(astrcpy(&first,second)){
		puts(first);
	}
	printf("***Cleaning Up***\n");	
	//free(first);
}