#include <cstdio>
#include <set>
#include <string>

#define MAX 112345

using namespace std;

int main(void){
  set <string> set;
  char s[MAX];

  while(scanf("%s", s) != EOF){
    set.insert(s);
  }
  printf("%d\n", (int)set.size());

  return 0;
}
