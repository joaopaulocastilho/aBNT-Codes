#include<stdio.h>
int main(){
    int n=1,maior=0,x,posicao;

    while (n<100){
        scanf("%d",&x);

        if (x>maior)    {maior=x;posicao=n;}
        n+=1;
    }
    printf("%d\n%d\n",maior,posicao);

return 0;}
