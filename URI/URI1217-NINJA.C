#include<stdio.h>
#include<string.h>

int main(){
    int N,kg=1,day=1,i;
    double V;
    char frutas[1000];
    scanf("%d",&N);
    while (N--){
        memset(frutas,'0',1000);
        scanf("%lf",&V);
        scanf("%s",&frutas);
        for(i=0;i!='/0';i++)
            if(frutas[i]=='\n')kg++;
        printf("%s",frutas);
        printf("%d\n",kg);

    }
}
