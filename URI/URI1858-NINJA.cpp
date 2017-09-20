#include <stdio.h>
int main(void){
	int i,menor,indmenor=0,N,T;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&T);
		if(T<menor || !indmenor){
			indmenor = i;
			menor = T;
		}
	}
	printf("%d\n",indmenor);
	return 0;
}
