//Adhoc
#include <stdio.h>
#include <stdlib.h>

#define MAX 112

int main(void){
    int i,p,n,f = 1,canos[MAX];

    scanf("%d %d",&p,&n);
    for(i = 0; i < n; i++) scanf("%d",&canos[i]);
    for(i = 0; i < n-1; i++) if(abs(canos[i] - canos[i + 1]) > p) f = 0;
    if (f) printf("YOU WIN\n");
    else printf("GAME OVER\n");
    return 0;
}
