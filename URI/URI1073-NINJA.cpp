#include <stdio.h>
    int main()  {
    int n,cont=1;
    scanf("%d",&n);
        if (n>5 && n<2000){
    while (cont<=n){
        if (cont%2==0)  {printf("%d^2 = %d\n",cont,cont*cont);}
        cont +=1;
    }   }

    return 0;}
