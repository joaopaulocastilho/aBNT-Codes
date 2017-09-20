#include <stdio.h>

int main(void){
    int p, q, product;
    double total = 0;
    scanf("%d", &p);
    while(p--){
        scanf("%d %d", &product, &q);
        switch(product){
            case 1001: total += 1.5 * q; break;
            case 1002: total += 2.5 * q; break;
            case 1003: total += 3.5 * q; break;
            case 1004: total += 4.5 * q; break;
            case 1005: total += 5.5 * q; break;
        }
    }
    printf("%.2lf\n", total);
}
