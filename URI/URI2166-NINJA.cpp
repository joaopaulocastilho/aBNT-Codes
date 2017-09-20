#include <stdio.h>

double fracp(int n){
    if(n == 0) return 0;
    return 1/ (2 + fracp(n-1));
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("%.10lf\n",1 + fracp(n));
    return 0;
}
