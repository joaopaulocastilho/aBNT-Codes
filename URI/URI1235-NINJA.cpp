#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int n, end, i, j;
  char line[MAX], ans[MAX], lixo;

  scanf("%d%c", &n, &lixo);
  while(n--){
    fgets(line, MAX, stdin);
    line[strlen(line)-1] = 0;
    //printf("%s\n", line);
    end = strlen(line);
    for(j = 0, i = end/2 - 1; i >= 0; i--) ans[j++] = line[i];
    for(i = end-1; i >= end/2; i--) ans[j++] = line[i];
    ans[j] = 0;
    //for(i = end-1; ans[i] == ' '; ans[i--] = 0); 
    printf("%s\n", ans);
  }
  return 0;
}
