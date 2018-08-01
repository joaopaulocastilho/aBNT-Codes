#include <stdio.h>
#include <string.h>

#define MAX 112
#define vog(c) (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')

int main(void){
  int i, j, end, ans = 1;
  char str[MAX], voga[MAX];

  scanf("%s", str);
  for(j = i = 0, end = strlen(str); i < end; i++)
    if(vog(str[i])) voga[j++] = str[i];
  voga[j] = 0;
  //printf("%s\n", voga);
  for(i = 0, j = strlen(voga)-1; i < j; i++, j--)
    if(voga[i] != voga[j]) ans = 0;
  printf("%s\n", ans ? "S" : "N");
  
  return 0;
}
