#include <stdio.h>
#include <string.h>
typedef unsigned long long ull;

typedef struct{
	ull num;
	char nome[200],escolha[10];
}jogador;

int main(void){
	jogador a,b;
	int N;
	scanf("%d\n",&N);
	while(N--){
		scanf("%s %s %s %s\n",a.nome,a.escolha,b.nome,b.escolha);
		scanf("%lld %lld",&a.num,&b.num);
		if( (a.num+b.num) % 2 == 0) printf("%s\n", !strcmp(a.escolha,"PAR") ? a.nome : b.nome );
		else printf("%s\n", !strcmp(a.escolha,"IMPAR") ? a.nome : b.nome );
	}
	return 0;
}
