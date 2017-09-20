#include <stdio.h>
#include <string.h>


int main(void){
    int volunteers[10001];
    int a, n, r, flag, i;
    while(1){
        flag = 0;

        if(scanf("%d %d", &n, &r) == EOF) return 0;
        memset(volunteers, 0, sizeof(volunteers));
        for(i = 0; i < r; i++){
            scanf("%d", &a);
            volunteers[a-1] = 1;
        }
        for(i = 0; i < n; i++){
            if(volunteers[i] == 0){
                printf("%d ", i+1);
                flag = 1;
            }
        }
        if(flag == 0) printf("*");
        printf("\n");
    }
    return 0;
}
