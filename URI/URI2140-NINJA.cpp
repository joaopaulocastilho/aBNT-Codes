#include <stdio.h>

#define MAX 112
#define TOTALC 21

int main(void){
    int n, m, troco, possible;
    int i, j, k, comb[MAX], notas[] = {2, 5, 10, 20, 50, 100};
    for(i = k = 0; i < 6; i++)
        for(j = i; j < 6; j++) comb[k++] = notas[i] + notas[j];
    while(scanf("%d %d", &n, &m), n || m){
        troco = m - n;
        for(i = possible = 0; i < TOTALC; i++){
            if(troco == comb[i]) possible = 1;
        }
        if(possible) printf("possible\n");
        else printf("impossible\n");
    }
    return 0;
}
