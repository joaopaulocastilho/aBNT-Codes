#include<stdio.h>
    int main(void) {
    int cod,qt;
    double ttl;
    scanf("%d %d",&cod,&qt);
    if (cod==1)
        ttl=qt*4.00;
    if (cod==2)
        ttl=qt*4.50;
    if (cod==3)
        ttl=qt*5.00;
    if (cod==4)
        ttl=qt*2.00;
    if (cod==5)
        ttl=qt*1.50;
    printf("Total: R$ %.2lf\n",ttl);
        return 0;


    }
