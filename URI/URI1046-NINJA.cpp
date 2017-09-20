#include<stdio.h>
    int main()  {
    int ini,fin,temp;
    scanf("%d %d",&ini,&fin);
        if (fin>ini) { temp=fin-ini; printf("O JOGO DUROU %d HORA(S)\n",temp);}
        else {temp=24-ini+fin; printf("O JOGO DUROU %d HORA(S)\n",temp);}


    return 0;   }
