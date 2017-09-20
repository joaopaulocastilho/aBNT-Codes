#include <stdio.h>

int main(void){
    int n, num;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &num);
        if(2015-num > 0) printf("%d D.C.\n", 2015-num);
        else printf("%d A.C.\n", (2015-num)*-1+1);
    }
    return 0;
}
