#include <stdio.h>
#include <string.h>
#define MAX 112

int norange(char c){
	if(c >= 'a' && c <= 'z') return 1;
	else if (c >= 'A' && c <= 'Z') return 2;
	return 0;
}

int main(void){
	char str[MAX];
	int f,i;
	while(fgets(str,MAX,stdin) != NULL){
		str[strlen(str) - 1] = '\0';
		for(i=0; i < (int)strlen(str); i++) 
			if(norange(str[i]) == 2) str[i] += 32;
//puts(str);
		for(i=0,f = 1; i < (int)strlen(str); i++){
			if(f && norange(str[i]) ){
				str[i] -= 32;
				f = 0;
			}
			else if(norange(str[i])) f = 1;
		}
		puts(str);
	}
	
	return 0;
}
