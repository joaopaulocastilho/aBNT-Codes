#include<stdio.h>
#include<string.h>
int main(){
    int n,k,p,i,v[200],resp=0;
    memset(v, 0, (sizeof(v)) );
    scanf("%d %d",&n,&k);
    while (n!=0 || k!=0){
        while (n--){
            scanf("%d",&p);
            v[p]+=1;
        }
        for(i=0;i<200;i++) if (v[i]>=k) resp++;
        printf("%d\n",resp);
        scanf("%d %d",&n,&k);
        resp=0;
        memset(v, 0, (sizeof(v)) );
    }


    return 0;
}
