#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>

#define MAX 112345

using namespace std;

int main(void){
  char str[MAX];

  while(scanf("%s\n", str), strcmp(str, "#")){
    if(next_permutation(str, str + strlen(str))) printf("%s\n", str);
    else printf("No Successor\n");
  }
  
  return 0;
}
