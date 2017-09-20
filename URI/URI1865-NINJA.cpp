#include <stdio.h>
#include <string.h>

int main(void){
	int C,D;
	char nome[100];
	scanf("%d\n",&C);
	while(C--){
		scanf("%s %d\n",nome,&D);
		if( !strcmp(nome,"Thor") ) printf("Y\n");
		else printf("N\n");
	}

	return 0;
}
