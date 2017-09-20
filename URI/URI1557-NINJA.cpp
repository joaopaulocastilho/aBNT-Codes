#include <stdio.h>

#define MAX 20

int main(void){
    int n, m[MAX][MAX], x, y, i, j, num, space;

    while(scanf("%d", &n), n){
        for(x = y = 0,num = 1; x < n; num *= 2, y == n-1 ? x++ : y++){
            for(i = x, j = y; i < n; i++, j--){
                m[i][j] = num;
            }
        }
        num = m[n-1][n-1];
        space = 0;
        while(num){
            space++;
            num/= 10;
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(j) printf(" ");
                printf("%*d",space, m[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
