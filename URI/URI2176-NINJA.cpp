#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
    int i, cont;
    char c, str[MAX];
    scanf("%s", str);
    for(i = cont = 0; i < strlen(str); i++)
        if(str[i] == '1') cont++;
    printf("%s%c\n", str, cont % 2 ? '1' : '0');
    return 0;
}
