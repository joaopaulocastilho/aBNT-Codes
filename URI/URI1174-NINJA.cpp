#include<stdio.h>
int main(){
    int i;
    double a[99];

    for (i=0;i<100;i++)
        scanf("%lf",&a[i]);
    for (i=0;i<100;i++)
        if (a[i]<=10) printf("A[%d] = %.1lf\n",i,a[i]);

    return 0;
}
