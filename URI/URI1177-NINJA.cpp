#include<stdio.h>
int main(){
    int v[999],i,n,x=0;
    scanf("%d",&n);

    for (i=0;i<1000;i++){
        v[i]=x;
        x++;
        if (x==n) {x=0;}
    }

    for (i=0;i<1000;i++)
        printf("N[%d] = %d\n",i,v[i]);
    return 0;
}
