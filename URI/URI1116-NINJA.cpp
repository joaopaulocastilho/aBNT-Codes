#include<stdio.h>
int main(){
int x,y,n;
double div;
    scanf("%d",&n);
        while (n>0){

            scanf("%d %d",&x,&y);
            if (y==0) {printf("divisao impossivel\n");}
            else {div=(double)x/(double)y;
            printf("%.1lf\n",div);}
            n-=1;
        }



return 0;
}
