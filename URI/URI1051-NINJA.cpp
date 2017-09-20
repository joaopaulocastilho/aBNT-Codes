#include<stdio.h>
    int main()  {
    double sal=0,imp=0,faixa1=0,faixa2=0,faixa3=0;
    scanf("%lf",&sal);
    if (sal<=2000.00) {printf("Isento\n");}
    if (sal>2000.00 && sal<=3000.00) {faixa1=(sal-2000.)*8./100.;printf("R$ %.2lf\n",faixa1);}
    if (sal>3000.00 && sal<=4500.00) {faixa2=(sal-3000.)*18./100.;faixa1=(1000*8.)/100.;printf("R$ %.2lf\n",faixa1+faixa2);}
    if (sal>4500.00) {faixa3=(sal-4500)*28./100.;faixa2=(1500*18)/100;faixa1=(1000*8)/100;printf("R$ %.2lf\n",faixa1+faixa2+faixa3);}






return 0;}
