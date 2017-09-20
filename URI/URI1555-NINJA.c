#include<stdio.h>

int r(x,y){
    return (3*x)^2+y^2;
}

int b(x,y){
    return 2*(x^2)+(5*y)^2;
}
int c(x,y){
    return -100*x+y^3;
}

int main(){
    int n,x,y;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&x,&y);
        if (b(x,y)> c(x,y) && b(x,y)> r(x,y)) printf("Beto ganhou\n");
        else if (c(x,y)>b(x,y) && c(x,y)>r(x,y)) printf("Carlos ganhou\n");
        else printf("Rafael ganhou\n");
    }

    return 0;
}
