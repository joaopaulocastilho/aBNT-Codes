#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 112
#define VOWEL(c) ((c) == 'A' || (c) == 'E' || (c) == 'I' || (c) == 'O' || (c) == 'U' || (c) == 'Y')

int main(void){
  int end, i;
  char str[MAX], big, curr;

  scanf("%s\n", str);
  end = strlen(str);
  for(i = big = 0, curr = 1; i < end; i++, curr++){
    if(VOWEL(str[i])){
      big = max(curr, big);
      curr = 0;
    }
  }
  big = max(curr, big);
  printf("%d\n", big ? big : 1);
    
  return 0;
}
