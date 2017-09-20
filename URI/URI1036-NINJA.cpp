#include<stdio.h>
#include<math.h>
    int main(void) {
        double A,B,C,R1,R2,D;
    scanf("%lf %lf %lf",&A,&B,&C);
        D=(B*B)-(4*A*C);
        R1= (   (-1*B) + (sqrt(D))  ) / (2*A);
        R2= (   (-1*B) - (sqrt(D))  )/ (2*A);
    if  (D>0 && A>0)
    {printf("R1 = %.5lf\n" , R1);
     printf("R2 = %.5lf\n" , R2);}
    else
        printf("Impossivel calcular\n");

        return 0;


    }
