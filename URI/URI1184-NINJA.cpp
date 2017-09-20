#include<stdio.h>
int main(){
    double M[100][100],soma=0;
    int n,i,j,cont=0;
    char c;
    scanf("%c",&c);

    for (i=0;i<12;i++)
        for (j=0;j<12;j++)
            scanf("%lf",&M[i][j]);

    /*for (i=0;i<4;i++)
        for (j=0;j<4;j++){
            printf("%.0lf",M[i][j]);
            if (j==3) printf("\n");
        }*/

    for (i=0;i<12;i++)
        for (j=0;j<12;j++)
            if (i>j){
            soma+=M[i][j];
            cont++;
            }

    if (c=='S'){
        printf("%.1lf\n",soma);
    }else if (c=='M'){
        printf("%.1lf\n",soma/cont);}

    return 0;
}
