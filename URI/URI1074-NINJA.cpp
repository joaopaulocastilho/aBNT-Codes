#include<stdio.h>
    int main()  {
    int y,x;
    scanf("%d",&y);

    if (y < 10000){
    while (y>0)
    {
        scanf("%d",&x);
        if (x%2==0 && x>0)  {printf("EVEN POSITIVE\n");}
        if (x%2!=0 && x>0)  {printf("ODD POSITIVE\n");}
        if (x%2==0 && x<0)  {printf("EVEN NEGATIVE\n");}
        if (x%2!=0 && x<0)  {printf("ODD NEGATIVE\n");}
       if (x==0) {printf("NULL\n");}
       y -= 1;

    }   }
    return 0;}
