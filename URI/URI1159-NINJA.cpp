#include<stdio.h>
int main(){
    int x=1,i=0,soma=0;
    scanf("%d",&x);
    while (x!=0){
        while (i<5){
            if (x%2==0){soma+=x; x+=2;i++;}
            else {x++;}
        }
    printf("%d\n",soma);
    i=soma=0;
    scanf("%d",&x);
    }

    return 0;
}
