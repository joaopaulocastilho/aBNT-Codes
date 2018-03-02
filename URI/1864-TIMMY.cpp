#include <cstdio>

int main(void){
    int num;
    char frase[50] = "LIFE IS NOT A PROBLEM TO BE SOLVED";
    
    scanf("%d", &num);
    for(int i = 0; i < num; i++) printf("%c", frase[i]);
    printf("\n");
    
    
    return 0;
}
