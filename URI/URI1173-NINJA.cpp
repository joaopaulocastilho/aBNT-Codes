#include<stdio.h>
int main(){
    int i,x,n[10];
    scanf("%d",&n[0]);
    for(i=1;i<=10;i++)
        n[i]=2*n[i-1];
    for(i=0;i<10;i++)
        printf("N[%d] = %d\n",i,n[i]);
    return 0;
}
