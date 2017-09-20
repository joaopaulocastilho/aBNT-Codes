#include <stdio.h>


int main(void){
    int n, a, b, ac, bc;

    while(scanf("%d", &n) && n != 0){
        ac = bc = 0;
        while(n--){
            scanf("%d%d", &a, &b);
            if(a == b);
            else (a > b) ? ac++ : bc++;
        }
        printf("%d %d\n", ac, bc);
    }
    return 0;
}
