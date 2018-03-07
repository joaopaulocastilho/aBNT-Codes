#include <stdio.h>
#include <string.h>

#define MAX 512

int main(void){
  int end, i, n, alfa[MAX], todo = 26;
  char str[MAX];
  
  memset(alfa, 0, sizeof(alfa));
  scanf("%d\n", &n);
  scanf("%s ", str);
  end = strlen(str);
  for(i = 0; i < end; i++){
    if(str[i] >= 'A' && str[i] <= 'Z') str[i] += ' ';
    //printf("%c", str[i]);
    if(!alfa[str[i]]){ todo--; alfa[str[i]] = 1; }
  }
  printf("%s\n", todo ? "NO" : "YES");
  
  return 0;
}
