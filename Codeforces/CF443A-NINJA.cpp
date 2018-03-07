#include <stdio.h>
#include <string.h>

#define MAX 300

int main(void){
  int ans = 0, letters[MAX];
  char c;

  memset(letters, 0, sizeof(letters));
  while(scanf("%c", &c) != EOF){
    if(c < 'a' || c > 'z') continue;
    if(!letters[c]){
      ans++;
      letters[c] = 1;
    }
  }
  printf("%d\n", ans);
  
  return 0;
}
