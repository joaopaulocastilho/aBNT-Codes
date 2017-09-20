#include <stdio.h>

int main(void){
    int i, NC, v[5], count;

    while(scanf("%d", &NC) && NC != 0){
        while(NC--){
            count = 0;
            for(i = 0; i < 5; i++){
                scanf("%d", &v[i]);
                if(v[i] <= 127) count++;
            }
            getchar();
            if(count > 1 || count == 0) printf("*\n");
            else if(v[0] <= 127) printf("A\n");
            else if(v[1] <= 127) printf("B\n");
            else if(v[2] <= 127) printf("C\n");
            else if(v[3] <= 127) printf("D\n");
            else if(v[4] <= 127) printf("E\n");
        }
    }
    return 0;
}
