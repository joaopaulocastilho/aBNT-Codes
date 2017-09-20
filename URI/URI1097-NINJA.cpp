#include<stdio.h>
int main(){
int I=1,J=7;

    while (I<=9){

        printf("I=%d J=%d\n",I,J);
        if (J-I==4){I+=2 ; J+=5;}
         J-=1;
    }

return 0;}
