#include <stdio.h>
int main(void){
	int gritos = 3,resultado=0,i,x;
	char str[10];
	while(gritos){
		fgets(str,10,stdin);
		if( str[0] == 'c' ){
			printf("%d\n",resultado);
			gritos--;
			resultado = 0;
		}
		else
			for(i=0,x=4;i<4;i++,x/=2) if (str[i] == '*') resultado+=x;
	}
	
}
