#include<stdio.h>
int main()  {
    char c;
    int n,x=0,tc=0,tr=0,ts=0,ttl=0;

    scanf("%d",&n);

    while (n--){

        scanf("%d %c",&x,&c);

        ttl+=x;

        switch (c)  {
        case 'C' :tc+=x;    break;
        case 'R' :tr+=x;    break;
        case 'S' :ts+=x;    break;
        }


    }
        printf("Total: %d cobaias\n",ttl);
        printf("Total de coelhos: %d\n",tc);
        printf("Total de ratos: %d\n",tr);
        printf("Total de sapos: %d\n",ts);
        printf("Percentual de coelhos: %.2lf %%\n",((double)tc*100.)/ttl );
        printf("Percentual de ratos: %.2lf %%\n",((double)tr*100.)/ttl   );
        printf("Percentual de sapos: %.2lf %%\n",((double)ts*100.)/ttl   );

    return 0;
    }
