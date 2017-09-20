#include <stdio.h>

#define ull unsigned long long

int main(void){
    ull x, m;
    while(scanf("%llu %llu", &x, &m), x || m){
        printf("%llu\n", x*m);
    }
    return 0;
}
