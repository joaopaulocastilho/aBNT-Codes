#include<stdio.h>
#include<string.h>
int main(){
    int n,x,d[100],e[100],resp=0,i;
    char c;
    while(scanf("%d",&n)!=EOF){
        memset(d,0,sizeof(d));
        memset(e,0,sizeof(e));
        while(n--){
            scanf("%d %c",&x,&c);
            switch(c){
            case 'D': d[x]++; break;
            case 'E': e[x]++; break;
            }
        }
        for (i=0;i<100;i++){ if (d[i]<e[i]) resp+=d[i]; else resp+=e[i]; }
        printf("%d\n",resp);
        resp=0;
    }
    return 0;
}
