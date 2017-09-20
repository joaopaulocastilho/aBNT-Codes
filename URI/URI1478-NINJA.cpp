#include <stdio.h>

#define MAX 112

int main(){
    int n, i, j, m[MAX][MAX], num, x, y;

    while(scanf("%d", &n), n){
        for(x = n-1, y = 0, num = n; !(!x && y == n); x ? (x--,num--) : (y++,num++)){
            for(i = x, j = y; i < n && j < n; i++, j++) m[i][j] = num;
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(j) printf(" ");
                printf("%3d", m[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
