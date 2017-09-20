#include<stdio.h>
    int main()  {
    double a,b,c,d,e,f,soma,mediador;
    scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f);
    if (a>0){ soma+=a;mediador+=1; }
    if (b>0){ soma+=b;mediador+=1; }
    if (c>0){ soma+=c;mediador+=1; }
    if (d>0){ soma+=d;mediador+=1; }
    if (e>0){ soma+=e;mediador+=1; }
    if (f>0){ soma+=f;mediador+=1; }
    printf("%.0lf valores positivos\n",mediador);
    printf("%.1lf\n",soma/mediador);
    return 0;}
