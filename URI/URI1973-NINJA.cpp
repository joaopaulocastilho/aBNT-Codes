#include <stdio.h>

#define MAX 1123456
#define ull unsigned long long

typedef struct star{
    int sheep;
    int attacked;
}star_t;

star_t stars[MAX];

int main(void){
    int n, i, flag, atckds;
    ull total;
    scanf("%d", &n);
    for(atckds = total = i = 0; i < n; i++){
        scanf("%d", &stars[i].sheep);
        total += stars[i].sheep;
        stars[i].attacked = 0;
    }
    for(i = 0; i < n && i >= 0; flag ? i-- : i++){
        if(stars[i].sheep % 2) flag = 0;
        else flag = 1;
        if(stars[i].sheep){
            total--;
            stars[i].sheep--;
        }
        if(!stars[i].attacked){
            atckds++;
            stars[i].attacked++;
        }
    }
    printf("%d %llu\n", atckds, total);
    return 0;
}
