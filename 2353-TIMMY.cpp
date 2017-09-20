#include <stdio.h>
#include <math.h>

int primo(int n){
    int i;
    for(i = 2; i <= sqrt(n); i++)
        if(n % i == 0) return 0;
    return 1;
}

int main(void){
    int i, n;
    scanf("%d", &n);
    for(i = n; !primo(i); i--){}
    printf("%d\n", i);
    return 0;
}
