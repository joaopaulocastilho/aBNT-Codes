#include <stdio.h>
#include <string.h>
#include <set>

using namespace std;

int main(void){
  int t, i, n, num, ans;

  scanf("%d", &t);
  while(t--){
    set <int> s;
    scanf("%d", &n);
    for(ans = i = 0; i < n; i++){
      scanf("%d", &num);
      if(s.find(num) == s.end()){
	s.insert(num);
	ans++;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
