#include <stdio.h>
#include <string.h>



int main(void){
    int nc, np, count, v[100][100], ns[100], as[100], alpr[100], alpe[100], i, j, ResolveuTudo, ResolveramUm, TodosResolveram, NinguemResolveu;

    scanf("%d %d", &nc, &np);
    while(nc != 0 && np != 0){
        ResolveuTudo = ResolveramUm = TodosResolveram = NinguemResolveu = count = 0;
        memset(ns, 0, sizeof(ns));
        memset(as, 0, sizeof(as));
        memset(alpr, 0, sizeof(alpr));
        memset(alpe, 0, sizeof(alpe));
        for(i = 0; i < nc; i++){ // Ler a matriz;
            for(j = 0; j< np; j++){
                scanf("%d", &v[i][j]);
                if(v[i][j] == 0){
                    ns[j] = 1;              // Nenhum problema foi solucionado por todo mundo;
                    as[i] = 1;              // Nenhuma pessoa resolveu todos os problemas;
                }
                else if(v[i][j] == 1){
                    alpr[j] = 1;            // Alguem solucionou esse problema;
                    alpe[i] = 1;            // Todo mundo solucionou pelo menos um problema;
                }
            }
        }
        for(i = 0; i < nc; i++){
            if(as[i] == 0) ResolveuTudo = 1;
            if(alpe[i] == 0) ResolveramUm = 1;
        }
        for(i = 0; i < np; i++){
            if(ns[i] == 0) TodosResolveram = 1;
            if(alpr[i] == 0) NinguemResolveu = 1;
        }
        if(!ResolveuTudo) count++;
        if(!ResolveramUm) count++;
        if(!TodosResolveram) count++;
        if(!NinguemResolveu) count++;
        printf("%d\n", count);
        scanf("%d %d", &nc, &np);
    }
    return 0;
}
