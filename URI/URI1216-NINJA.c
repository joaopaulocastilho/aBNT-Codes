#include<stdio.h>
int main(){
    char nome[100];
    double d,soma=0,i=0;
    while (scanf("%s",&nome)!=EOF){
        scanf("%lf",&d);
        soma+=d;
        i++;
    }
    printf("%.1lf\n",soma/i);

    return 0;
}
