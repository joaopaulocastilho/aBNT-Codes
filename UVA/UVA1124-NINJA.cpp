#include <stdio.h>
#include <string.h>
int main(){
	char l1[10];
	
	while( fgets(l1,10,stdin) ){
		l1[strlen(l1) - 1] = '\0';
		puts(l1);
	}

	return 0;
}

