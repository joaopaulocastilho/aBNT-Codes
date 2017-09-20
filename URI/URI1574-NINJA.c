#include<stdio.h>
int main(){
    int p=0,T,n,i=1,u;
    char inst[200],c,comandos[200];
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        while(n--){
            for(i=0;inst[i-1]!='\n';i++) scanf("%c",&inst[i]);
            if (inst[0]=='L') {p--; inst[i]='L';}
            if (inst[0]=='R') {p++; inst[i]='R';}
            if (inst[0]=='S') {c=inst[8]; printf("%c",&inst[6]);}

        }
        printf("%d\n",p);
        p=0;
        i=1;
    }


    return 0;
}
