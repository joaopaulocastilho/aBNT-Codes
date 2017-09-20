#include<stdio.h>
int main(){
    int i,v[19],n=19,temp;
    for(i=0;i<20;i++)
        scanf("%d",&v[i]);
    for (i=0;i<20;i++)
        printf("N[%d] = %d\n",i,v[i]);

    for (i=0;i<n;i++){
        temp=v[i];
        v[i]=v[n];
        v[n]=temp;
        n--;
    }
    for (i=0;i<20;i++)
        printf("N[%d] = %d\n",i,v[i]);


    return 0;
}
