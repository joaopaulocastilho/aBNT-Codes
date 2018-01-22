#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void){
  int ans, first;
  char letter, line[MAX], word[MAX];
  long long int off;
  
  while(fgets(line, MAX, stdin), line[0] != '*'){
    off = 0;
    ans = first = 1;
    while(sscanf(line+off, "%s ", word) != EOF){
      if(word[0] < 'a') word[0] += ' ';
      off += strlen(word) + 1;
      if(first){ letter = word[0]; first = 0; }
      else if(word[0] != letter) ans = 0;
    }
    printf("%c\n", ans ? 'Y' : 'N');
  }
  return 0;
}
