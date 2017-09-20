#include<stdio.h>
int main(){
    int q,d,p,x;
    scanf("%d",&q);
    while(q!=0){
        scanf("%d %d",&d, &p);
        x=p*( (q*d)/(p-q) );
        if (x==1)printf("%d pagina\n",x);
        else    printf("%d paginas\n",x);
        scanf("%d",&q);
    }

    return 0;
}
