#include <stdio.h>

#define ull unsigned long long

int main(void){
    ull n;
    scanf("%llu", &n);
    printf("%llu\n", (n*(n-3))/2);
    return 0;
}
