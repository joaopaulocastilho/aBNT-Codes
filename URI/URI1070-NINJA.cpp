#include<stdio.h>
    int main()  {
        int x=0,y=0,f=0,soma=0;
        scanf("%d %d",&x,&y);
        if (x==y || y==x) printf("0\n");

    if(x>y)     {
        if (y%2==0)     {y+=1;}
    f=x-y;
        while (f>=0){
            soma+=y;
            f -= 2;
            y+=2; }

        printf("%d", soma);}


    return 0;}
