#include<stdio.h>
    int main(){
        double soma=0.0,divisor=0.0,idade=0.0;

        while (idade>=0)
        {
            scanf("%lf",&idade);
            if (idade>0){
            divisor+=1;
            soma+=idade;}

        }
        printf("%.2lf\n",soma/divisor);
    return 0;}
