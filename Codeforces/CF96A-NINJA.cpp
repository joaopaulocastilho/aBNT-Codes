#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, ans, qtd, end;
  char str[MAX];

  scanf("%s ", str);
  end = strlen(str);
  for(ans = 0, qtd = i = 1; i < end; i++){
    if(str[i] == str[i-1]) qtd++;
    else qtd = 1;
    if(qtd == 7) ans = 1;
  }
  printf("%s\n", ans ? "YES" : "NO");
  
  return 0;
}
