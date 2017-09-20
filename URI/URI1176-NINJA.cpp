#include<stdio.h>
int main(){
    unsigned long long v[100],a=0,b=1,aux;
    int i,n;

    for(i=0;i<101;i++){
        v[i]=a;
        aux=a+b;
        a=b;
        b=aux;
    }
    for(i=0;i<60;i++) printf("V[%d] %llu\n",i,v[i]);

    scanf("%d",&n);
    while (n--){
        scanf("%d",&i);
        printf("Fib(%d) = %llu\n",i,v[i]);
    }

}
