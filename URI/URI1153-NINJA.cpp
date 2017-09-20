#include<stdio.h>
int main(){
int n,c;
    scanf("%d",&n);
    c=n;

        while (c>1){
        c-=1;
        n*=c;
        }

    printf("%d\n",n);
return 0;}
