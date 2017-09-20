#include<stdio.h>
int main(){
    int N,s[2000],maior=0,segundo=-1,i,resp=0;
    scanf("%d",&N);
    while(N!=0){
        for(i=1;i<=N;i++){
            scanf("%d",&s[i]);
            if (s[i]>maior){segundo=maior; maior=s[i];}
            else if(s[i]>segundo) segundo=s[i];
        }
        for(i=1;i<=N;i++) {if(s[i]==segundo)resp=i;}
        printf("%d\n",resp);
        maior=0;
        segundo=-1;
        scanf("%d",&N);
    }

    return 0;
}
