#include<stdio.h>
int main(){
    int N,i,r,M=0,J=0;
    scanf("%d",&N);
    while(N!=0){
        for(i=0;i<N;i++){
            scanf("%d",&r);
            r==1 ? J++ : M++;
        }
    printf("Mary won %d times and John won %d times\n",M,J);
    M=J=0;
    scanf("%d",&N);
    }
    return 0;
}
