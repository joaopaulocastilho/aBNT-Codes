#include <stdio.h>

int main(void){
    int t, n;
    while(scanf("%d", &t), t){
        while(t--){
            scanf("%d",&n);
            if(n % 2 == 0) printf("%d\n", (2*(n-2)) + 2);
            else printf("%d\n", (2*(n-1)) + 1);
        }
    }
    return 0;
}
