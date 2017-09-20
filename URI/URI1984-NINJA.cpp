//Adhoc
#include <stdio.h>

typedef unsigned long long ull;

int main(void){
    ull num;

    scanf("%llu",&num);
    while(num){
        printf("%llu",num % 10);
        num/=10;
    }
    printf("\n");

    return 0;
}
