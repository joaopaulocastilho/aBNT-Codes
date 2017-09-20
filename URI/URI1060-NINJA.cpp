#include<stdio.h>
    int main()  {
    double a,b,c,d,e,f,soma=0;
    scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f);
    if (a>0){ soma +=1; }
    if (b>0){ soma +=1; }
    if (c>0){ soma +=1; }
    if (d>0){ soma +=1; }
    if (e>0){ soma +=1; }
    if (f>0){ soma +=1; }
    printf("%.0lf valores positivos\n",soma);

    return 0;}
