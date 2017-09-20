#include<stdio.h>
    int main(){
    double s=1,div=2;

        while (div<=100){

           s+=(1/div);
           div+=1;
        }
        printf("%.2lf\n",s);



    return 0;
    }
