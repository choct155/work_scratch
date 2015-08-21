#include <stdio.h>

int main(void){
	if (1 || 0 && 0){
		printf("Hello, world.\n");	
		printf("%d",(1 || 0 && 0));
	}
    else{
    	printf("Womp womp.\n");
    }
    return 0;
}
