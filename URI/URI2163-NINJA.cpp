#include <stdio.h>
#define MAX 1123

int main(void){
    int i, j, n, m, x = -1, y = -1, ans = 0, field[MAX][MAX];
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++) scanf("%d", &field[i][j]);
    for(i = 1; i < n-1; i++)
        for(j = 1; j < m-1; j++){
            if(field[i][j] == 42){
                ans = 1;
                for(int k = i-1; k <= i+1; k++)
                    for(int l = j-1; l <= j+1; l++)
                        if(field[k][l] != 7 && k != i && l != j){
                            ans = 0;
                        }
            }
            if(ans){
                x = i;
                y = j;
                ans = 0;
            }
        }
    printf("%d %d\n", x+1, y+1);

    return 0;
}
