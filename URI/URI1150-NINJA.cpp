#include <stdio.h>
int main(){
    int x=0,z=0,soma,i=1;
    scanf("%d",&x);
    while (x>=z){scanf("%d",&z);}
    soma=x;
    while(soma<z){
        soma+=x+1;
        x++;
        i++;
    }
    printf("%d\n",i);

    return 0;
}
