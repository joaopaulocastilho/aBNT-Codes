#include<stdio.h>
int main(){
    int N,QT,i,S,AL[20],menor=1000000,resp;
    scanf("%d",&N);
    while(N--){
        scanf("%d %d",&QT,&S);
        for(i=1;i<=QT;i++){
            scanf("%d",&AL[i]);
            AL[i]>=S ? AL[i]-=S : (AL[i]=S-AL[i]);
            if (AL[i]<menor){
                menor=AL[i];
                resp=i;
            }
        }
        printf("%d\n",resp);
        menor=1000000;
    }

    return 0;
}
