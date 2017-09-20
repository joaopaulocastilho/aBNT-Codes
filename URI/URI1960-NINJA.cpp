#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    if(n >= 900){printf("CM"); n-=900;}
    else if(n >= 500){printf("D"); n-=500;}
    else if(n >= 400){printf("CD"); n-= 400;}
    while(n >= 100){printf("C"); n-=100;}
    if(n >= 90){printf("XC"); n-= 90;}
    else if(n >= 50){printf("L"); n-= 50;}
    else if(n >= 40){printf("XL"); n-= 40;}
    while(n >= 10){printf("X"); n-= 10;}
    if(n == 9){printf("IX"); n -= 9;}
    else if(n >= 5){printf("V"); n-= 5;}
    if(n == 4){printf("IV"); n -= 4;}
    while(n){printf("I"); n--;}
    printf("\n");
    return 0;
}
