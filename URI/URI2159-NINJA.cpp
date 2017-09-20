#include <stdio.h>
#include <math.h>

#define CONS 1.25506

int main(void){
    double n;
    scanf("%lf", &n);
    printf("%.1lf %.1lf\n", n/log(n), CONS * n/log(n));
    return 0;
}
