#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 110

int main(void){
  int tc;
  char word[MAX];
  scanf("%d", &tc);
  while(tc--){
    int count = 0;
    scanf("%s", word);
    if(strlen(word) <= 10) printf("%s\n", word);
    else{
      printf("%c", word[0]);
      for(int i = 1; i < (int) strlen(word) - 1; i++) count++;
      printf("%d", count);
      printf("%c\n", word[strlen(word)-1]);
    }
  }
  return 0;
}
