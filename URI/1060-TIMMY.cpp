#include <cstdio>

int main(void){
    int i, count;
    double valor;
    for(i = 0, count = 0; i < 6; i++){
        scanf("%lf", &valor);
        if(valor > 0) count++;
    }
    printf("%d valores positivos\n", count);
    return 0;
}
