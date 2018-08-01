#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 11234

int main(void){
  int ans, i, t, n, v[MAX];
  
  scanf("%d", &t);
  while(t--){
    vector<int> v2;
    scanf("%d", &n);
    for(ans = i = 0; i < n; i++){
      scanf("%d", &v[i]);
      v2.push_back(v[i]);
    }
    sort(v2.begin(), v2.end());
    for(i = 0; i < n; i++)
      if(v[i] == v2[i]) ans++;
    printf("%d\n", ans);
  }

  return 0;
}
