#include <stdio.h>
#define MAX 1123456
int main(void){
	int A,B,soma,i;
	int num[MAX];
	while(scanf("%d %d",&A,&B), A || B){
		i = 0;
		soma = A+B;
		while(soma){
			num[i++] = soma%10;
			soma/=10;
		}
		for(i-=1;i>=0;i--) if(num[i]) printf("%d",num[i]);
		printf("\n");
	}

}
