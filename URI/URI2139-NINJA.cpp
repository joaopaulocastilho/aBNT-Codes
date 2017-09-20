#include <stdio.h>

#define NATAL 360

int main(void){
    int mes, dia, atual, i;
    while(scanf("%d %d", &mes, &dia) != EOF){
        for(i = 1, atual = 0; i < mes; i++){
            if(i == 2) atual += 29;
            else if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10
                || i == 12) atual += 31;
            else atual += 30;
        }
        atual += dia;
        if(NATAL - atual == 1) printf("E vespera de natal!\n");
        else if(!(NATAL - atual)) printf("E natal!\n");
        else if(NATAL - atual < 0) printf("Ja passou!\n");
        else printf("Faltam %d dias para o natal!\n", NATAL - atual);
    }
    return 0;
}
