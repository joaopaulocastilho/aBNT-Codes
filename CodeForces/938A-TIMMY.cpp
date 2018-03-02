#include <cstdio>
#include <cstring>

#define MAX 1123

int vogal(char c){
  if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
    return 1;
  else return 0;
}
 
int main(void){
  char word[MAX];
  int tc;
  scanf("%d", &tc);
  scanf("%s", word);
  for(int i = 0; i < strlen(word)-1; i++)
    while(vogal(word[i]) && vogal(word[i+1]))
      for(int j = i+1; j < strlen(word); j++)
	word[j] = word[j+1];
  printf("%s\n", word);
  return 0;
}
