#include <stdio.h>

int main(void)   {
	double hormes,amhour,SALARY ;
	int NUMBER ;
	scanf("%d %lf %lf" , &NUMBER , &hormes , &amhour);
	SALARY = hormes*amhour ;
	printf("NUMBER = %d\n", NUMBER );
	printf("SALARY = U$ %.2lf\n" , SALARY);
	return 0;
                 }
