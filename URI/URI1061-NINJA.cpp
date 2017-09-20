#include<stdio.h>
int main(){
    int di,hi,mi,si,df,hf,mf,sf,ti,tf,dt=0;
    scanf("Dia %d\n%d : %d : %d\nDia %d\n%d : %d : %d",&di,&hi,&mi,&si,&df,&hf,&mf,&sf);
    ti=(hi*3600)+(mi*60)+si;
    tf=(hf*3600)+(mf*60)+sf;
    tf-=ti;
    if (tf<0){
    tf+=86400;
    dt-=1;
    }
    dt+=df-di;
    printf("%d dia(s)\n",dt);
    printf("%d hora(s)\n",tf/3600);
    tf-=(tf/3600)*3600;
    printf("%d minuto(s)\n",tf/60);
    tf-=(tf/60)*60;
    printf("%d segundo(s)\n",tf);


    return 0;
}
