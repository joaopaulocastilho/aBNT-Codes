#include<stdio.h>
int main(){
int x=1,c=1;

    while (x!=0){

        scanf("%d",&x);
            while (c<x){

                printf("%d ",c);
                c+=1;

            }
             if (c=x){printf("%d\n",x);}
            c=1;
    }

return 0;}
