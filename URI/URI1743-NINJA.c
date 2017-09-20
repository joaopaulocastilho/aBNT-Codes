#include<stdio.h>
int main(){
    int v1[10],v2[10],n=0,i;
    for (i=0;i<=4;i++) scanf("%d",&v1[i]);
    for (i=0;i<=4;i++) scanf("%d",&v2[i]);
    for (i=0;i<=4;i++){
        if (v1[i] == v2[i])
        n++;
    }
    n>0? printf("N\n") : printf("Y\n");
}
