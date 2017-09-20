#include <stdio.h>
#include <math.h>

#define PI 3.14

int main(void){
    double v, d, area;
    while(scanf("%lf %lf", &v, &d) != EOF){
        area = PI * pow(d/2, 2);
        printf("ALTURA = %.2lf\n", v/area);
        printf("AREA = %.2lf\n", area);
    }
    return 0;
}
