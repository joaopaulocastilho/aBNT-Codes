#include <stdio.h>
#include <string.h>

#define MAX 11234

int main(void){
    int c;
    char str[MAX];
    scanf("%d", &c);
    while(c--){
        scanf("%s\n", str);
        printf("%.2lf\n", strlen(str) * 0.01);
    }
    return 0;
}
