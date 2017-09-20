#include<stdio.h>
int main(){
    int h1,m1,h2,m2,t1,t2,tt;
    scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
    while(h1!=0 || h2!=0 || m1!=0 || m2!=0){
        t1=h1*60+m1;
        t2=h2*60+m2;
        tt=t2-t1;
        if(tt<0){tt+=1440;}
        printf("%d\n",tt);
        scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
    }
    return 0;
}
