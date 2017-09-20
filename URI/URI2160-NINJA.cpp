#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void){
    char line[MAX];
    fgets(line, MAX, stdin);
    line[strlen(line) - 1] = '\0';
    if(strlen(line) > 80) printf("NO\n");
    else printf("YES\n");
    return 0;
}
