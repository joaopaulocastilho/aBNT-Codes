#include <stdio.h>

double fracp(int n){
    if(n == 0) return 0;
    return 1/ (6 + fracp(n-1));
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("%.10lf\n",3 + fracp(n));
    return 0;
}
