#include <stdio.h>
#include <math.h>

int main(void){
    int q, d, p, x;
    while(1){
        scanf("%d", &q);
        if(q == 0) return 0;
        scanf("%d %d", &d, &p);

        x = (double) (q*d)/(p-q)*p;
        x = floor(x);
        if(x == 1) printf("%d pagina\n", x);
        else printf("%d paginas\n", x);
    }
}
