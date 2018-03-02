#include <cstdio>

int main(void){
    int valor, tc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &valor);
        if(2015 - valor > 0) printf("%d D.C.\n", 2015-valor);
	else if(2015 - valor == 0) printf("%d A.C.\n", 2015-valor + 1);
        else printf("%d A.C.\n", (2015-valor-1)*-1);
    }
    return 0;
}
