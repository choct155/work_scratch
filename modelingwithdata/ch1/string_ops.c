/*Program demonstrates string manipulation operations*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

char* astrcpy(char **base, const char *copyme){

<<<<<<< HEAD
	printf("\nWe are inside the function, astrncpy.\n");
	printf("\nThis function has accepted two arguments:\n");
	printf("**base > a pointer to the pointer array containing the string to be replaced.\n");
	printf("*copyme > the pointer array containing the replacement string.\n");
	printf("Note that copyme (sans star in the arg declaration) refers only to the identifying first position of the string.\n");
	printf("Note also that we use **base because the values in that location must be modified.\n");
	printf("Modifying a copy of the string does us no good, but a copy of the pointer points to the same location.\n");
	printf("Therefore, modifying the value at the location identified by the pointer copy modifies the original string.\n");
	printf("\nCopying '%s' (*copyme) into a location currently featuring the following string: '%s' (**base)\n", copyme,*base);
	printf("The location of our string to be copied (%s) is %p.\n", copyme, &copyme);
=======
	printf("Copying '%s' into a location currently featuring the following string: '%s'\n", copyme,*base);
	printf("The location of our string to be copied (%s) is %p.\n", copyme, (const void *) copyme);
>>>>>>> 79c1f15aa9a190e8fab8e6d3530c20be47271998
	printf("The location of our string to be replaced (%s) is %p.\n", *base, base);

	//Declare string length variable
	size_t new_len=strlen(copyme);
<<<<<<< HEAD
	printf("Calculating new length for replaced memory allocation (%d).\n",new_len);

	//Reallocate pointer array
	printf("Reallocating memory block associated with base string to be replaced.\n");
	*base=realloc(*base,sizeof(char)*(new_len+1));
	

	//Copy copyme content to base string location
	strncpy(*base,copyme,new_len);

	printf("The string at location %p is now '%s'\n", base, *base);
	
}

void astrncat(char **base, char *appendme){

	printf("\nWe are inside the function, astrncat.\n");
	printf("\nThis function has accepted two arguments:\n");
	printf("**base > a pointer to the pointer array containing the string to be replaced.\n");
	printf("*appendme > the pointer array containing the replacement string.\n");
	printf("Note that appendme (sans star in the arg declaration) refers only to the identifying first position of the string.\n");
	printf("Note also that we use **base because the values in that location must be modified.\n");
	printf("Modifying a copy of the string does us no good, but a copy of the pointer points to the same location.\n");
	printf("Therefore, modifying the value at the location identified by the pointer copy modifies the original string.\n");
	printf("\nConcatenating '%s' (*appendme) into a location currently featuring the following string: '%s' (**base)\n", appendme,*base);
	printf("The location of our string to be appended (%s) is %p.\n", appendme, &appendme);
	printf("The location of our string to be augmented (%s) is %p.\n", *base, base);

	//Declare string length variable
	size_t new_len=strlen(appendme)+strlen(*base);
	printf("Calculating new length for replaced memory allocation (%d).\n",new_len);

	//Reallocate pointer array
	printf("Reallocating memory block associated with base string to be replaced.\n");
	*base=realloc(*base,sizeof(char)*(new_len+1));
	

	//Copy copyme content to base string location
	strncat(*base,appendme,new_len);

	printf("The string at location %p is now '%s'\n", base, *base);
=======
	printf("***Calculating new length for replaced memory allocation (%zu).***\n",new_len);

	printf("***Reallocating memory allocation.***\n");
	//Generate temporary character object
	char *tmp;
	//If reallocation is possible...
	if (*tmp=realloc(*base,sizeof(char)*(new_len+1)) != NULL){
		//...assign that block to *base...
		*base=tmp;	
>>>>>>> 79c1f15aa9a190e8fab8e6d3530c20be47271998
	
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
	char first_lit2[]="Fortran? ";
	char second2[]="Now that's a name I've not heard in a long time.";

<<<<<<< HEAD
	//Capture elements of first_lit in pointer array (so we can get at the pointer to the strings pointer)
	char *first; //Declare pointer to pointer array that represents the first string
	first=malloc((strlen(first_lit)+1)*sizeof(char)); //Allocate space for the pointer array
	strncpy(first,first_lit,strlen(first_lit)); //Assign values to the pointer locations

	char *first2; //Declare pointer to pointer array that represents the first string
	first2=malloc((strlen(first_lit2)+1)*sizeof(char)); //Allocate space for the pointer array
	strncpy(first2,first_lit2,strlen(first_lit2)); //Assign values to the pointer locations

	//Copy copyme into base
	printf("Initiating copy operation...\n");
	astrncpy(&first,second);

	//Concatenate appendme onto base
	printf("Initiating concatenation operation...\n");
	astrncat(&first2,second2);

	printf("\nLet's move on to printing to strings instead of standard out with asprintf.\n");
	char *line;
	asprintf(&line,"%s is number %i in line","Bob",3);
	printf("%s\n",line );
	printf(line);
	printf("asprintf seems like a handy way to convert numbers to strings\n");

=======
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
>>>>>>> 79c1f15aa9a190e8fab8e6d3530c20be47271998
}