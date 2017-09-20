#include <stdio.h>

#define MAX 112

int main(void){
    int n, i, j, m[MAX][MAX];
    scanf("%d", &n);
    for(i = 0; i <= n; i++)
        for(j = 0; j <= n; j++) scanf("%d", &m[i][j]);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(m[i][j] + m[i][j+1] + m[i+1][j] + m[i+1][j+1] < 2) printf("U");
            else printf("S");
        }
        printf("\n");
    }
    return 0;
}
