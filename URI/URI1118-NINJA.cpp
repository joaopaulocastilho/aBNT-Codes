#include<stdio.h>
int main(){
double nota1=0,nota2=0,decision=0;
    while (decision!=2){
        decision=7;
        while(nota1==0){
        scanf("%lf",&nota1);
        if (nota1>10 || nota1<0){nota1=0;printf("nota invalida\n");}
        }
        while(nota2==0){
        scanf("%lf",&nota2);
        if (nota2>10 || nota2<0){nota2=0;printf("nota invalida\n");}
        }
        printf("media = %.2lf\n",(nota1+nota2)/2);
        nota1=nota2=0;
        while (decision!=1 && decision!=2){
        printf("novo calculo (1-sim 2-nao)\n");
        scanf("%lf",&decision);
        }

    }



return 0;
}
