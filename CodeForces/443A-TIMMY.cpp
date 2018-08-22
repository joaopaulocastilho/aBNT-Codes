#include <cstdio>
#include <set>

using namespace std;

int main(void){
  char letter,junk, comma;
  set<char> s;
  scanf("%c%c", &junk, &letter);
  if(letter == '}'){ printf("0\n"); return 0; }
  scanf("%c", &comma);
  s.insert(letter);
  while(scanf(" %c%c", &letter, &comma), comma != '}'){
    s.insert(letter);
  }
  s.insert(letter);
  printf("%d\n", (int)s.size());
  return 0;
}
