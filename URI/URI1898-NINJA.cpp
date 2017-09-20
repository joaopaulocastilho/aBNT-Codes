#include <stdio.h>
#include <string.h>
#define MAX 100

int main(void){
	int cpfc=11,ponto,numponto,i,div,cpfin=0;
	char linha1[MAX],linha2[MAX],cpf[MAX];
	double num1,num2;
	num1=num2=0;
	fgets(linha1,MAX,stdin);
	fgets(linha2,MAX,stdin);
	ponto = 0;
	div=10;
	numponto = 2;
	linha1[strlen(linha1) - 1] = '\0';
	linha2[strlen(linha2) - 1] = '\0';
	for (i =0; i< strlen(linha1); i++){
		if(linha1[i] >= '0' && linha1[i]<= '9'){
			if(cpfc){
				cpf[cpfin++] = linha1[i];
				cpfc--;
			}
			else if (!ponto){
				num1*=10;
				num1+=linha1[i] - '0';
			}
			else if(numponto){
				num1+= (double)(linha1[i] - '0') / div;
				numponto--;
				div*=10;
			}
		}
		else if( linha1[i] == '.') ponto = 1;
	}
	cpf[cpfin] = '\0';
	ponto=0;
	div=10;
	numponto = 2;
	for ( i=0; i<strlen(linha2);i++){
		if(linha2[i] >= '0' && linha2[i]<= '9'){
			if (!ponto){
				num2*=10;
				num2+=linha2[i] - '0';
			}
			else if(numponto){
				num2+= (double)(linha2[i] - '0') / div;
				numponto--;
				div*=10;
			}
		}
		else if( linha2[i] == '.') ponto = 1;
	}
	
	
	
	printf("cpf %s\n",cpf);
	//printf("%lf\n",num1);
	//printf("%lf\n",num2);
	printf("%.2lf\n",num1+num2);
	
	return 0;
}
