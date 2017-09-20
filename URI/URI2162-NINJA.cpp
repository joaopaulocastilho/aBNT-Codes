#include <stdio.h>

#define MAX 112;

int main(void){
    int n, ant, atual, first = 1, ans = 1, subiu = -1;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &atual);
        if(!first){
            if(atual == ant) ans = 0;
            if(subiu != -1){
                if(subiu && atual > ant) ans = 0;
                else if(!subiu && atual < ant) ans = 0;
            }
            subiu = atual > ant ? 1 : 0;
        }
        else first = 0;
        ant = atual;
    }
    printf("%d\n", ans);
    return 0;
}
