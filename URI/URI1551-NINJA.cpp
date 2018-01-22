#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void){
  int i, t, end, cont, alfa[MAX];
  char str[MAX];

  scanf("%d ", &t);
  while(t--){
    memset(alfa, 0, sizeof(alfa));
    fgets(str, MAX, stdin);
    end = strlen(str) - 1;
    for(i = cont = 0; i < end; i++){
      if(alfa[str[i]] || str[i] < 'a' || str[i] > 'z') continue;
      alfa[str[i]] = 1;
      cont++;
    }
    if(cont == 26) printf("frase completa\n");
    else if(cont >= 13) printf("frase quase completa\n");
    else printf("frase mal elaborada\n");
  }
  return 0;
}
