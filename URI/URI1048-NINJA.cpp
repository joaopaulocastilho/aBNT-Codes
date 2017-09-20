#include<stdio.h>
    int main()  {
    double salario,salario2,reajuste,indice;
    scanf("%lf",&salario);
    if (salario>=0 && salario<=400.00) {reajuste=(salario*15.)/100.; salario2=salario+reajuste;
    printf("Novo salario: %.2lf\n",salario2); printf("Reajuste ganho: %.2lf\n",reajuste); printf("Em percentual: 15 %%\n");}
        if (salario>=400.01 && salario<=800.00) {reajuste=(salario*12./100.); salario2=salario+reajuste;
        printf("Novo salario: %.2lf\n",salario2); printf("Reajuste ganho: %.2lf\n",reajuste); printf("Em percentual: 12 %%\n");}
    if (salario>=800.01 && salario<=1200.00) {reajuste=(salario*10.)/100.; salario2=salario+reajuste;
    printf("Novo salario: %.2lf\n",salario2); printf("Reajuste ganho: %.2lf\n",reajuste); printf("Em percentual: 10 %%\n");}
        if(salario>=1200.01 && salario<=2000.00) {reajuste=(salario*7.)/100.; salario2=salario+reajuste;
        printf("Novo salario: %.2lf\n",salario2); printf("Reajuste ganho: %.2lf\n",reajuste); printf("Em percentual: 7 %%\n");}
    if (salario>2000.00) {reajuste=(salario*4.)/100.; salario2=salario+reajuste;
    printf("Novo salario: %.2lf\n",salario2); printf("Reajuste ganho: %.2lf\n",reajuste); printf("Em percentual: 4 %%\n");}

    return 0; }
