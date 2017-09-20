//adhoc
#include <stdio.h>

int main(void){
    int n,matricula,melhorm = -1;
    double nota,melhorn = 8;
    scanf("%d",&n);
    while(n--){
        scanf("%d %lf",&matricula,&nota);
        if(nota >= melhorn){
            melhorn = nota;
            melhorm = matricula;
        }
    }
    if(melhorm != -1) printf("%d\n",melhorm);
    else printf("Minimum note not reached\n");
    return 0;
}
