#include<stdio.h>
#include<string.h>
int main(){
    int N,M,T,v[25000],resp=0;
    scanf("%d %d",&N,&M);
        while (M!=0 || N!=0){
        memset(v,0,sizeof(v));
            while(M--){
                scanf("%d",&T);
                v[T]++;
            }
        for(T=1;T<20001;T++) if(v[T]>1) resp++;
        printf("%d\n",resp);
        resp=0;
        scanf("%d %d",&N,&M);
        }

    return 0;
}
