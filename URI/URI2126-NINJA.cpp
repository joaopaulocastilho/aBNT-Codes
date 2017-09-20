#include <stdio.h>

#define MAX 112

int main(void){
    int i, j, k, lastpos, qtd, equal, caso = 1;
    char str1[MAX], str2[MAX];

    while(scanf("%s\n", str1) != EOF){
        scanf("%s\n", str2);
        for(lastpos = qtd = i = j = 0; str2[i] != '\0'; i++){
            for(equal = 1, j = 0, k = i; str2[k] != '\0' && str1[j] != '\0'; k++, j++){
                if(str1[j] != str2[k]){
                    equal = 0; break;
                }
            }
            if(equal && str1[j] == '\0'){
                qtd++;
                lastpos = i;
            }
        }
        printf("Caso #%d:\n", caso++);
        if(qtd){
            printf("Qtd.Subsequencias: %d\n", qtd);
            printf("Pos: %d\n", lastpos + 1);
        }
        else printf("Nao existe subsequencia\n");
        printf("\n");
    }
    return 0;
}
