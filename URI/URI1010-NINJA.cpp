#include <stdio.h>

int main(void)   {
	int cod1,num1,cod2,num2;
	double val1,val2,total;
	scanf("%d %d %lf" , &cod1 , &num1 , &val1);
	scanf("%d %d %lf" , &cod2 , &num2 , &val2);
	val1 = val1*num1;
	val2 = val2*num2;
	total = val2+val1;
	printf("VALOR A PAGAR: R$ %.2lf\n", total);
	return 0 ;
		}
