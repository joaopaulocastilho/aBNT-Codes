#include<stdio.h>
int main(){
    int V[510],n,L,i,maior=-1;
    scanf("%d",&L);
    do {for(i=0;i<=L;i++){
            scanf("%d",&V[i]);
            if (V[i]>maior) maior=V[i];
        }

        if (maior<10) printf("1\n");
        else if(maior>=10 && maior<20) printf("2\n");
        else printf("3\n");
    }while(scanf("%d",&L)!=EOF);
    return 0;
}
