#include<stdio.h>
int main(){
    int n,x,i=1,soma=0;
    scanf("%d",&n);
    while (n--){
        scanf("%d",&x);
        while(i!=x){
            if(x%i==0){soma+=i;}
            i++;
        }
    if (soma==x){printf("%d eh perfeito\n",x);}
    else {printf("%d nao eh perfeito\n",x);}
    soma=0;
    i=1;
    }

    return 0;
}
