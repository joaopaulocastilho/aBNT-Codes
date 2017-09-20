#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 11234
int main(void){
	int T,op;
	char str1[MAX],str2[MAX];
	scanf("%d\n",&T);
	while(T--){
		op = 0;
		scanf("%s %s",str1,str2);
		for(int i=0;strcmp(str1,str2);){
			if(str1[i] == str2[i]) i++;
			else{
				if(str1[i] != 'z') str1[i]++;
				else str1[i] = 'a';
				op++;
			}  
		} 
//puts(str1); puts(str2);
		printf("%d\n",op);
	}
	return 0;
}

	

