#include <stdio.h>
int main(void)	{
	double A,B,C,tri,cir,trap,quad,ret;
	scanf("%lf %lf %lf" , &A , &B , &C);
	tri = A*C/2;
	cir = C*C*3.14159;
	trap = (A+B)*C/2;
	quad = B*B;
	ret = A*B;
	printf("TRIANGULO: %.3lf\n" , TRIANGULO);
	printf("CIRCULO: %.3lf\n" , CIRCULO);
	printf("TRAPEZIO: %.3lf\n" , TRAPEZIO);
	printf("QUADRADO: %.3lf\n" , QUADRADO);
	printf("RETANGULO: %.3lf\n" , RETANGULO);
	return 0;
                 } 	
