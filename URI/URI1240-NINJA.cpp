#include <stdio.h>

int encaixa(int a,int b){
	if(a < b) return 0;
	while(b){
		if(a % 10 != b%10) return 0;
		a/=10;
		b/=10;
	}
	return 1;
}

int main(void){
	int T;
	int a,b;
	scanf("%d\n",&T);
	while(T--){
		scanf("%d %d\n",&a,&b);
		printf("%s\n", encaixa(a,b) ? "encaixa" : "nao encaixa" );
	}

	return 0;
}
