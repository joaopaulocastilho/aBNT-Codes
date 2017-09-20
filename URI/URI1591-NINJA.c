#include <stdio.h>
#include <string.h>
#define MAX 100

int main() {
	int T,L,C,i,j,P,I,J,tam,resp,igual;
	char caca[MAX][MAX],palavra[MAX],c;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&L,&C);
		for(i=0;i<L;i++)
			for(j=0;j<C;){
				scanf("%c",&c);
				if (c != '\n'){
					caca[i][j]=c;
					j++;
				}
			}
		scanf("%d\n",&P);
		while(P--){
			resp=0;
			fgets(palavra,100,stdin);
			tam = strlen(palavra);
			palavra[tam-1] = '\0';
			tam = strlen(palavra);
			for(i=0;i<L;i++)
				for(j=0;j<C;j++){
					igual=0;
					if(j + tam <= C)
						igual=1;
						for(J=j,I=0;I<tam;J++,I++)
							if(palavra[I] != caca[i][J]) igual= 0;
					if (igual) resp++;
					igual=0;
					if(i + tam <= L)
						igual=1;
						for(I=i,J=0;J<tam;J++,I++)
							if(palavra[J] != caca[i][J]) igual= 0;
					if (igual) resp++;		
				}
			printf("%d\n",resp);	
		}
			
	}
	
	
	return 0;
}
