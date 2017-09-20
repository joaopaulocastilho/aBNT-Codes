#include<stdio.h>
    int main()  {
    int N,val=1;
    scanf("%d",&N);


        while (val<=10000)
        {
            if (val%N==2){printf("%d\n",val);}
            val +=1;

        }


    return 0;}
