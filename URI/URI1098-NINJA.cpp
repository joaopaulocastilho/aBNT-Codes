#include<stdio.h>
int main(){
    double i=0,j=1,cont=0;
    while (i<=2){
        if (i>0.8 && i<1.2){printf("I=%.0lf J=%.0lf\n",i,j);}
        else if ((int)i==i || i>1.8){printf("I=%.0lf J=%.0lf\n",i,j);}
        else{printf("I=%.1lf J=%.1lf\n",i,j);}
        j+=1;
        cont+=1;
        if (cont==3){i+=0.2;j-=2.8; cont=0;}


    }
    return 0;
}
