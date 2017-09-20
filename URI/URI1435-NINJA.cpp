#include <stdio.h>
#include <algorithm>

#define MAX 112

using namespace std;

int main(){
    int n, i, j, m[MAX][MAX], start, limit, x;

    while(scanf("%d", &n), n){
        for(start = 0, limit = n, x = 1; start < limit; start++, limit--, x++){
            for(i = start ; i < limit; i++){
                for(j = start; j < limit; j++){
                    m[i][j] = x;
                }
            }
        }
        for(i = 0; i < n; i++){
            //printf(" ");
            for(j = 0; j < n; j++){
                if(j > 0) printf(" ");
                printf("%3d", m[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
