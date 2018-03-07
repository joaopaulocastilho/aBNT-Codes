#include <stdio.h>
#include <set>
#include <string>

using namespace std;

#define MAX 1123

int main(void){
  char str[MAX];
  int n, ans = 151;
  set<string> pome;
  
  scanf("%d", &n);
  while(n--){
    scanf("%s ", &str);
    if(pome.find(str) == pome.end()){
      pome.insert(str);
      ans--;
    }
  }
  printf("Falta(m) %d pomekon(s).\n", ans);
  
  return 0;
}
