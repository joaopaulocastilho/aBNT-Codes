#include <cstdio>
#include <cstring>

#define MAX 112345

int main(void){
  char string[MAX];
  int t, count;

  scanf("%d", &t);
  while(t--){
    count = 0;
    scanf(" %s", string);
    int len = strlen(string);
    for(int i = 0; i < len; i++)
      if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' ||
	 string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')
	count++;
    printf("%d\n", count);
  }
  return 0;
}
