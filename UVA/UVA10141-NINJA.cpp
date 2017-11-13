#include <stdio.h>
#include <string.h>
#define MAX 1123456789
int main(){
	int n,p,r,cont=1;
	char nome[100],nomelhor[100],lixo[100];
	double melhor,prec,melhorp;
	scanf("%d %d\n",&n,&p);
	while(n){
		melhor=-1;
		melhorp=MAX;
		for (int i=0;i<n;i++){	
			fgets(lixo,100,stdin);
		}
//printf("Acabei de ler os lixos\n");
		for (int i=0;i<p;i++){
			fgets(nome,100,stdin);
//printf("nome :%s",nome);
			scanf("%lf %d\n",&prec,&r);
//printf("%lf %d",prec,r);
			//getchar();
			for (int i=0;i<r;i++) fgets(lixo,100,stdin);
			if( (double)r/n >= melhor){				//compliance
				if ( ((double)r/n) == melhor){
					if(prec<melhorp){
						melhor = (double)r/n;
						strcpy(nomelhor,nome);
						melhorp=prec;
					}
				}
				else{
					melhor = (double)r/n;
					strcpy(nomelhor,nome);
					melhorp=prec;
				}
			}
		
		}
		if(cont>1) printf("\n");
		printf("RFP #%d\n",cont++);
		printf("%s",nomelhor);
		scanf("%d %d\n",&n,&p);
	}
	
	return 0;
}
