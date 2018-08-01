#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
  int n, s, mini, val;

  scanf("%d %d", &n, &s);
  mini = s;
  while(n--){
    scanf("%d", &val);
    s += val;
    mini = min(s, mini);
  }
  printf("%d\n", mini);
  
  return 0;
}
