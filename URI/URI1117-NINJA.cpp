#include<stdio.h>
int main(){
double nota,soma;
int n=0;

    while (n<2){
        scanf("%lf",&nota);
        if (nota>=0 && nota<=10){soma+=nota; n+=1;}
        else {printf("nota invalida\n");}

    }
    printf("media = %.2lf\n",soma/2.);

return 0;
}
