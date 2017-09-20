#include<stdio.h>
    int main()  {
    int n;
    double a,b,c,media;
    scanf("%d",&n);
        while (n>0){
    scanf("%lf %lf %lf",&a,&b,&c);
    media=((2*a)+(3*b)+(5*c))/10;
    printf("%.1lf\n",media);
    n-=1;

        }



    return 0;}
