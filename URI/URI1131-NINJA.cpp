#include<stdio.h>
int main(){
int decision,g=0,i=0,vi=0,vg=0,e=0,contador=0;
    while (decision!=2){
        scanf("%d %d",&i,&g);

    if (i>g){vi+=1;}
    else if (g>i){vg+=1;}
    else {e+=1;}
    contador+=1;

    printf("Novo grenal (1-sim 2-nao)\n");
    scanf("%d",&decision);
    }
    printf("%d grenais\n",contador);
    printf("Inter:%d\n",vi);
    printf("Gremio:%d\n",vg);
    printf("Empates:%d\n",e);
    if (vg>vi){printf("Gremio venceu mais\n");}
    else {printf("Inter venceu mais\n");}


return 0 ;
}
