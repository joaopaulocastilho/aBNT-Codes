#include<stdio.h>
int main(){
int x,y,c=1,l;
    scanf("%d %d",&x,&y);
    l=x;
    while (c<=y){

        while (x!=1){
            printf("%d ",c);
            c+=1;
            x-=1;
    }
    printf("%d\n",c);
    c+=1;
    x=l;}
return 0;
}
