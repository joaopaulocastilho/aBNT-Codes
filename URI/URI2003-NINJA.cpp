//adhoc
#include <stdio.h>

int main(void){
    int h,m,t;
    t = 8 * 60;
    while( scanf("%d:%d",&h,&m) != EOF){
        m += h * 60 + 60;
        printf("Atraso maximo: %d\n", t - m < 0 ? (t - m) * -1 : 0 );
    }
    return 0;

}
