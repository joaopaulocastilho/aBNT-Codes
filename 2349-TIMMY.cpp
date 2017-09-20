#include <stdio.h>


int main(void){
    int n, c, s, comando, lugar = 1, count = 0;
    scanf("%d %d %d", &n, &c, &s);
    if(s == lugar) count++;
    while(c--){
        scanf("%d", &comando);
        if(comando == 1) lugar++;
        else lugar --;
        if(lugar > n) lugar = 1;
        else if(lugar < 1) lugar = n;
        if(lugar == s) count++;
    }
    printf("%d\n", count);
}
