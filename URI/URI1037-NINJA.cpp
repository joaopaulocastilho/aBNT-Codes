#include<stdio.h>
    int main(void)  {
    double x;
    scanf("%lf",&x);
    if (x<0)
    printf("Fora de intervalo\n");
    if (x>100)
    printf("Fora de intervalo\n");
    if (x>=0.000000 && x<=25.00000)
    printf("Intervalo [0,25]\n");
    if (x>=25.00001 && x<=50.0000000)
    printf("Intervalo (25,50]\n");
    if (x>=50.00001 && x<=75.0000000)
    printf("Intervalo (50,75]\n");
    if (x>=75.00001 && x<=100.0000000)
    printf("Intervalo (75,100]\n");

    return 0;



    }
