#include<stdio.h>
    int main(void)  {
    int dia,mes,ano,idad;
    scanf("%d" , &idad);
    ano=idad/365;
    idad=idad-ano*365;
    mes=(idad/30);
    idad=idad-mes*30;
    dia=idad;
    printf("%d ano(s)\n" , ano);
    printf("%d mes(es)\n" , mes);
    if (dia>=0)
    {printf("%d dia(s)\n" , dia);}
    else
    printf("0 dia(s)\n");
        return 0;
    }
