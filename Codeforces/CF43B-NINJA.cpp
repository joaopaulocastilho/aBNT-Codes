#include <stdio.h>
#include <string.h>

#define MAX 300

int main(void){
  char header[MAX], letter[MAX];
  int end, i, ans, alfa[MAX];

  memset(alfa, 0, sizeof(alfa));
  fgets(header, MAX, stdin);
  fgets(letter, MAX, stdin);
  header[strlen(header)-1] = letter[strlen(letter)-1] = 0;
  for(end = strlen(header), i = 0; i < end; i++) alfa[header[i]]++;
  for(ans = 1, end = strlen(letter), i = 0; i < end && ans; i++){
    //printf("%c\n", letter[i]);
    if(letter[i] == ' ') continue;
    if(alfa[letter[i]]) alfa[letter[i]]--;
    else ans = 0;
  }
  printf("%s\n", ans ? "YES" : "NO");
  
  return 0;
}
