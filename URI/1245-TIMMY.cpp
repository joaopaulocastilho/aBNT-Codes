#include <stdio.h>
#include <string.h>

int main(void){
    int NC, n, i, count, e[61], d[61];
    char p;

    scanf("%d", &NC);
    while(NC != EOF){
        count = 0;
        memset(d, 0, sizeof(d));
        memset(e, 0, sizeof(e));
        while(NC--){
            scanf("%d %c", &n, &p);
            if(p == 'E'){
                e[n]++;
            }
            else if(p == 'D') d[n]++;
        }
        for(i = 30; i <= 60; i++){
            while(e[i] != 0 && d[i] != 0){
                d[i]--;
                e[i]--;
                count++;
            }
        }
        printf("%d\n", count);
        scanf("%d", &NC);
    }
    return 0;
}
