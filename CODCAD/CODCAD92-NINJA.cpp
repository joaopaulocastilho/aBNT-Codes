#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int i, n, num, ans;
  vector<int> v;

  scanf("%d", &n);
  for(i = 0; i < 3; i++){
    scanf("%d", &num);
    v.push_back(num);
  }
  sort(v.begin(), v.end());
  for(ans = i = 0; v[i] <= n && i < v.size(); n -= v[i], i++, ans++);
  printf("%d\n", ans);
  
  return 0;
}
