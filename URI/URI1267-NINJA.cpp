#include <stdio.h>
#include <string.h>

#define MAX 112
int main(void){
	int i,j,N,D,alunos[MAX],foi,teve;
	while( scanf("%d %d",&N,&D),N || D){
		memset(alunos,0,sizeof(alunos));
		teve = 0;
		for(j = 0;j<D;j++)
		for(i=0;i<N;i++){
			scanf("%d",&foi);
			if(foi) alunos[i]++;
			if(alunos[i] == D) teve = 1;
		}
		if (teve) printf("yes\n");
		else printf("no\n");
	}
	
	
	
	return 0;
}
