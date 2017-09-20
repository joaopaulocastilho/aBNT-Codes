#include <stdio.h>

int main(void){
    int s, t, f, chegada;
    scanf("%d %d %d", &s, &t, &f);
    chegada = s + t + f;
    if(chegada < 0) printf("%d\n", chegada + 24);
    else if(chegada < 24) printf("%d\n", chegada);
    else printf("%d\n", chegada - 24);
    return 0;
}
