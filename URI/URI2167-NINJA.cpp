#include <stdio.h>

int main(void){
    int n, ant = -1, ans = 0, i = 1, atual;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &atual);
        if(ant != -1 && atual < ant){
            ans = i; break;
        }
        ant = atual;
        i++;
    }
    printf("%d\n", ans);
    return 0;
}
