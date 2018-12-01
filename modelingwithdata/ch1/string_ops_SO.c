#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * astrcpy( char **base, const char *copyme )
{
    printf( "Copying '%s' into a location currently featuring the following string: '%s'\n", copyme,*base );
    printf( "The location of our string to be copied (%s) is %p.\n", copyme, ( const void * )copyme );
    printf( "The location of our string to be replaced (%s) is %p.\n", *base,  ( void * )*base );

    //Declare string length variable
    size_t new_len = strlen( copyme );
    printf("Calculating new length for replaced memory allocation (%zu).\n", new_len );

    //Reallocate pointer array
    printf("Reallocating memory allocation.\n");

    char *tmp;
    if ( ( tmp = realloc( *base, sizeof( char ) * ( new_len + 1 ) ) ) != NULL )
    {
        *base = tmp;

        //Copy copyme content to base string location
        strcpy( *base, copyme );

        printf( "The string at location %p is now %s\n", ( void * )*base, *base );
    }

    return tmp;
}

int main( void )
{
    //Generate strings
    char first_lit[] = "Fortran?";
    char second[] = "Now that's a name I've not heard in a long time.";

    //Convert first string to array (so we can get at the pointer to the strings pointer)
    char *first; //Declare pointer to pointer array that represents the first string

    first = malloc( ( strlen( first_lit ) + 1 ) * sizeof( char ) ); //Allocate space for the pointer array
    strcpy( first, first_lit ); //Assign values to the pointer locations

    //Copy copyme into base
    if ( astrcpy( &first, second ) ) puts( first );

    free( first );
}