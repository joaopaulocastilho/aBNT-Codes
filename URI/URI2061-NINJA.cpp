#include <stdio.h>
#include <string.h>

#define MAX 20

int main(void){
    int n, m;
    char str[MAX];
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%s\n", str);
        if(!strcmp(str,"fechou")) n++;
        else n--;
    }
    printf("%d\n", n);
    return 0;
}
