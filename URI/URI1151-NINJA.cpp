#include<stdio.h>
int main(){
    int a=0,b=1,n,aux;
    scanf("%d",&n);
    while (--n){
        printf("%d ",a);
        aux=a+b;
        a=b;
        b=aux;
    }
    printf("%d\n",a);
    return 0;
}
