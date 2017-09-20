#include <stdio.h>

int main(void)   {
	char S[1000];
	double sal,sold,TOTAL,bon;
	fgets (S,1000,stdin);
	scanf("%lf %lf" , &sal , &sold);
	bon = 15*sold/100 ;
	TOTAL = bon + sal ;
	printf("TOTAL = R$ %.2lf\n", TOTAL);
	return 0 ;
		}
