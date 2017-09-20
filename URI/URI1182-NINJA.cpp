#include<stdio.h>
int main(){
    double M[100][100],soma=0;
    int n,i,j;
    char c;
    scanf("%d %c",&n,&c);

    for (i=0;i<12;i++)
        for (j=0;j<12;j++)
            scanf("%lf",&M[i][j]);

    /*for (i=0;i<4;i++)
        for (j=0;j<4;j++){
            printf("%.0lf",M[i][j]);
            if (j==3) printf("\n");
        }*/

        for (i=0;i<12;i++)
            soma+=M[i][n];

    if (c=='S'){
        printf("%.1lf\n",soma);
    }else if (c=='M'){
        printf("%.1lf\n",soma/12);}

    return 0;
}
