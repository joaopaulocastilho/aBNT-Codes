#include <stdio.h>
#include <string>

#define vowel(c) (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
#define MAX 112

using namespace std;

int main(void){
  int i, n;
  char str[MAX];
  string s;

  scanf("%d ", &n);
  scanf("%s ", str);
  s = string(str);

  for(i = 1; i < s.length();){
    if(vowel(s[i]) && vowel(s[i-1])) s.erase(i, 1);
    else i++;
  }
  printf("%s\n", s.c_str());
       
  return 0;
}
