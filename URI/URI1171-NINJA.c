#include<stdio.h>
#include<string.h>
int main(){
    int v[3000],n,x,i;
    memset(v, 0, (sizeof(v)) );
    scanf("%d",&n);
    while (n--){
        scanf("%d",&x);
        v[x]+=1;
    }
    for(i=0;i<3000;i++)
    if(v[i]!=0){printf("%d aparece %d vez(es)\n",i,v[i]);}
    return 0;
}
