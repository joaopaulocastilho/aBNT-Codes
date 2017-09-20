#include<stdio.h>
int main(){
    int n,x,y,soma=0;
    scanf("%d",&n);
    while (n--){
        scanf("%d %d",&x,&y);
        while (y){
            if (x%2!=0){soma+=x; x+=2; y--;}
            else{x++;}
        }
    printf("%d\n",soma);
    soma=0;
    }

    return 0;
}
