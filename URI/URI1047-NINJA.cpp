#include <stdio.h>
int main(){
    int hi,mi,hf,mf,ti,tf,ttl;
    scanf("%d %d %d %d",&hi,&mi,&hf,&mf);
    ti=hi*60+mi;
    tf=hf*60+mf;
    ttl=tf-ti;
    if (ttl==0){ttl=1440;}
    if (ttl<0) {ttl+=1440;}
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",ttl/60,ttl%60);

    return 0;
}
