#include <stdio.h>

int main(void){
    int are, u, i;
    char mine;
    while(scanf("%d", &are  )){
        if(are == 0) return 0;
        u = 1;
        for(i = 0; i <= are; i++){
            scanf("%c", &mine);
            if(mine == 'D'){
                u++;
                if(u == 5) u = 1;
            }
            else if(mine == 'E'){
                u--;
                if(u == 0) u = 4;
            }
        }
        if(u == 1) printf("N\n");
        else if(u == 2) printf("L\n");
        else if(u == 3) printf("S\n");
        else printf("O\n");
    }
    return 0;
}
