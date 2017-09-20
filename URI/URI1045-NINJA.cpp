#include<stdio.h>
int main(){
double a,b,c,A,B,C;
scanf("%lf %lf %lf",&a,&b,&c);

    if (a>=b && a>=c){A=a;}
    else if (b>=a && b>=c){A=b;}
    else {A=c;}

    if (a<=b && a<=c){C=a;}
    else if (b<=a && b<=c){C=b;}
    else {C=c;}

    if (A==a && C==b) {B=c;}
    else if (A==b && C==a) {B=c;}
    else if (A==c && C==a) {B=b;}
    else if (A==a && C==c) {B=b;}
    else if (A==c && C==b) {B=a;}
    else if (A==b && C==c) {B=a;}

    if (A>=(B+C)){printf("NAO FORMA TRIANGULO\n");}
    else if(A!=0 && B!=0 && C!=0){
    if ( (A*A)==(  (B*B)+(C*C) )) {printf("TRIANGULO RETANGULO\n");}
    if ( (A*A)>(  (B*B)+(C*C) )) {printf("TRIANGULO OBTUSANGULO\n");}
    if ( (A*A)<(  (B*B)+(C*C) )) {printf("TRIANGULO ACUTANGULO\n");}
    if (A==B && A==C) {printf("TRIANGULO EQUILATERO\n");}
    if (A==B && A!=C) {printf("TRIANGULO ISOSCELES\n");}
    if (C==B && C!=A) {printf("TRIANGULO ISOSCELES\n");}
    if (A==C && A!=B) {printf("TRIANGULO ISOSCELES\n");}
    }





return 0;
}
