#include<stdio.h>
int main(){
    int n,Ax,Ay,Bx,By,Cx,Cy,Dx,Dy,Rx,Ry;
    scanf("%d",&n);
    while(n--){
    scanf("%d %d %d %d %d %d %d %d %d %d",&Ax,&Ay,&Bx,&By,&Cx,&Cy,&Dx,&Dy,&Rx,&Ry);
    if(Rx>=Dx && Rx<=Cx && Ry>=Ay && Ry<=Dy) printf("1\n");
    else printf("0\n");
    }

    return 0;
}
