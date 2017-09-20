#include <stdio.h>

int main(void){
    long double num;
    scanf("%LE", &num);
    //if(num > 0) printf("+");
    printf("%+.4LE\n", num);
    return 0;
}
