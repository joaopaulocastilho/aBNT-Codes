#include<stdio.h>
int main(void) {
    int A,B,C,D,CD,AB;
    scanf("%d %d %d %d",&A,&B,&C,&D);
    CD=C+D;
    AB=A+B;
    if (B>C && D>A && CD>AB && C>0 && D>0 && A%2==0 )
    printf("Valores aceitos\n");
    else
    printf("Valores nao aceitos\n");

    return 0;
    }
