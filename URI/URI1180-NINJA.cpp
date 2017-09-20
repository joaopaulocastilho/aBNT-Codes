#include<stdio.h>
#define MIN 1123456789

int main(){
    int i,n,menor=MIN,pos;
    scanf("%d",&n);
    int v[n];

    for(i=0;i<n;i++){
        scanf("%d",&v[i]);
        if(v[i]<menor){menor=v[i]; pos=i;}
    }
    printf("Menor valor: %d\n",menor);
    printf("Posicao: %d\n",pos);
    return 0;
}
