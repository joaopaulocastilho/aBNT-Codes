#include <stdio.h>

#define MAX 112

int main(void){
    int n, i, j, m[MAX][MAX];

    while(scanf("%d", &n) != EOF){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i == j && (i + j)/2 == n/2) printf("4");
                else if(i >= n/3 && i <n-n/3 && j >= n/3 && j < n-n/3)
                    printf("1");
                else if(i + j == n-1) printf("3");
                else if(i == j) printf("2");
                else printf("0");
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
