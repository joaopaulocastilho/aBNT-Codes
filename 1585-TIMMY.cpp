#include <stdio.h>


int main(void){
    int NC, a, b;

    scanf("%d", &NC);
    while(NC--){
        scanf("%d %d", &a, &b);
        printf("%d cm2\n", ((a*b)/2));
    }

    return 0;
}
