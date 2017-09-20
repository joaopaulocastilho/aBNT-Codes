#include<stdio.h>
int main(){
int n,x,y,soma=0;
scanf("%d",&n);

    while (n--){
    scanf("%d %d",&x,&y);
        if (x>=y) {
        y+=1;
        if (y%2==0){y+=1;}
            while (y<x){
            if (y%2!=0){soma+=y;}
            y+=2;

                    }
                }
        if (y>=x) {
        x+=1;
        if (x%2==0){x+=1;}
            while(x<y){
            if (x%2!=0){soma+=x;}
            x+=2;
            }
        }


    printf("%d\n",soma);
    soma=0;
}

return 0;
}
