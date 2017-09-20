#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    int nc, a, b, c, closest, i, flag, number;

    scanf("%d", &nc);
    while(nc--){
        flag = 0;
        closest = 999;
        scanf("%d %d", &a, &b);
        for(i = 1; i <= a; i++){
            scanf("%d", &c);
            if(c == b){
                if(flag == 0) printf("%d\n", i);
                flag = 1;
            }
            else if(abs(b - c) < abs(b - closest)){
                closest = c;
                number = i;
            }
        }
        if(flag == 0) printf("%d\n", number);
    }

    return 0;
}
