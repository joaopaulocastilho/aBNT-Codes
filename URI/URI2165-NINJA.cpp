#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void){
    char str[MAX];
    fgets(str, MAX, stdin);
    printf("%s\n", strlen(str)-1 > 140 ? "MUTE" : "TWEET");
    return 0;
}
