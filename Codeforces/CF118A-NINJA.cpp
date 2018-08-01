#include <stdio.h>
#include <string.h>

#define MAX 112
#define vowel(c) (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')

int main(void){
  int i, end;
  char str[MAX];

  scanf("%s", str);
  for(end = strlen(str), i = 0; i < end; i++){
    if(str[i] >= 'A' && str[i] <= 'Z') str[i] += ' ';
    if(vowel(str[i])) continue;
       printf(".%c", str[i]);
  }

  return 0;
}
