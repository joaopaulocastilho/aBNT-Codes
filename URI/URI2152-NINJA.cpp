#include <stdio.h>

int main(void){
    int t, h, m, o;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &h, &m, &o);
        printf("%.2d:%.2d - A porta %s!\n", h, m, o ? "abriu" : "fechou");
    }
    return 0;
}
