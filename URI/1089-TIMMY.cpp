#include <stdio.h>
#include <string.h>

int main(void){
    int v[11234], i, count, NC;

    scanf("%d", &NC);
    while(NC != 0){
        memset(v, 0, sizeof(v));
        count = 0;
        for(i = 0; i < NC; i++){
            scanf("%d", &v[i]);
        }
        for(i = 0; i < NC; i++){
            if(i == 0){
                if((v[NC-1] > v[i] && v[i] < v[i+1]) || (v[NC-1] < v[i] && v[i] > v[i+1])) count++;
            }
            else if(i == (NC-1)){
                if((v[i-1] > v[i] && v[i] < v[0]) || (v[i-1] < v[i] && v[i] > v[0])) count++;
            }
            else if((v[i-1] < v[i] && v[i] > v[i+1]) || (v[i-1] > v[i] && v[i] < v[i+1])) count++;
        }
        printf("%d\n", count);
        scanf("%d", &NC);
    }
}
