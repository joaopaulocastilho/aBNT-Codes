#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void){
  int i, j, n, ans;
  char str1[MAX], str2[MAX];

  scanf("%d ", &n);
  while(n--){
    ans = 1;
    scanf("%s %s ", str1, str2);
    if(strlen(str2) > strlen(str1)) ans = 0;
    else
      for(i = strlen(str1), j = strlen(str2); j>= 0; i--, j--){
	if(str1[i] != str2[j]) ans = 0;
      }
    printf("%sencaixa\n", ans ? "" : "nao ");
  }

  return 0;
}
