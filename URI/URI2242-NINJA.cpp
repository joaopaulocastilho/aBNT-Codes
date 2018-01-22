#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, j, k, ans = 1;
  char str1[MAX], str2[MAX], vogais[] = {'a', 'e', 'i', 'o', 'u'};

  scanf("%s ", str1);
  for(i = k = 0; i < strlen(str1); i++){
    for(j = 0; j < 5; j++)
      if(str1[i] == vogais[j]) str2[k++] = str1[i];
  }
  str2[k] = 0;
  //printf("%s\n", str2);

  for(i = 0, j = strlen(str2) - 1; i < j; i++, j--)
    if(str2[i] != str2[j]) ans = 0;
  printf("%s\n", ans ? "S" : "N");
  
  return 0;
}
