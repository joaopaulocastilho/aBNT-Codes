#include<stdio.h>
int main(){
    int n,impar[4],y=15,i=0,j=0;
    int par[4];

    while (y--){
        scanf("%d",&n);
        if (n%2==0){
            par[i]=n;
            i++;
            if(i==5){
                for (i=0;i<5;i++)
                    printf("par[%d] = %d\n",i,par[i]);
                i=0;
            }
        }else{
            impar[j]=n;
            j++;
            if (j==5){
                for (j=0;j<5;j++)
                    printf("impar[%d] = %d\n",j,impar[j]);
                j=0;
            }
        }
    }
    for(n=j-1,j=0;n>=0;n--,j++)
        printf("impar[%d] = %d\n",j,impar[j]);
    for(n=i-1,i=0;n>=0;n--,i++)
        printf("par[%d] = %d\n",i,par[i]);


    return 0;
}
