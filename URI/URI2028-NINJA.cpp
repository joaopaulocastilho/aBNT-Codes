#include <stdio.h>

int contaDigitos(int n){
    if(n == 0) return 1;
    return n + contaDigitos(n-1);
}

int main(void){
    int n, caso = 1, i, j, digitos;

    while(scanf("%d", &n) != EOF){
        digitos = contaDigitos(n);
        printf("Caso %d: %d numero%s\n", caso++, digitos,
            digitos == 1 ? "" : "s");
        for(i = 0; i <= n; i++){
            if(i == 0) printf("0");
            else
                for(j = 0; j < i; j++) printf(" %d",i);
        }
        printf("\n\n");
    }
    return 0;
}
