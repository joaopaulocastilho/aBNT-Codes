#include <stdio.h>
#include <math.h>

int main(void){
    int x, y, percent, ans;

    while (scanf("%d", &x), x){
        scanf("%d %d", &y, &percent);
        ans = sqrt((100 * x * y) / percent);
        printf("%d\n", ans);
    }
    return 0;
}
