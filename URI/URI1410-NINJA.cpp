#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
	return *(int*)b - *(int*)a ; 
}

int main(void){
	int i,j,A,D,atacantes[20],defensores[20],impedido,resp;
	while( scanf("%d %d",&A,&D),A || D){
		resp = 0;
		for(i=0;i<A;i++) scanf("%d",&atacantes[i]);
		for(i=0;i<D;i++) scanf("%d",&defensores[i]);
		qsort(defensores,D,sizeof(int),cmp);
//for(int a= 0; a<D; a++) printf("%d,",defensores[a]);
//printf("\n");
		for(i=0;i<A;i++){
			impedido = 1;
			if(atacantes[i] >= defensores[D-2]) impedido = 0;
			if(impedido) resp  = 1;
		}
		if(resp) printf("Y\n");
		else printf("N\n");
	}
	return 0;
}
