#include <stdio.h>

int main(void)   {
	double nota1,nota2,nota3,MEDIA;
	scanf("%lf %lf %lf" , &nota1, &nota2,&nota3);
	MEDIA = (2*nota1 + 3*nota2 + 5*nota3)/(2 + 3 + 5);
	printf("MEDIA = %.1lf\n", MEDIA);
	return 0;
	}
