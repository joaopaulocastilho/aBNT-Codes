#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, j, end, ans = 1;
  char s[MAX], t[MAX];

  scanf("%s %s ", s, t);
  end = strlen(s);
  for(i = 0, j = strlen(t)-1; i < end && j >= 0; i++, j--){
    //printf("%c - %c\n", s[i], t[j]);
    if(s[i] != t[j]) ans = 0;
  }
  printf("%s\n", ans ? "YES" : "NO");
  
  return 0;
}
