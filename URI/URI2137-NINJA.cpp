#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int n, i, num;
  vector<int> v;

  while(scanf("%d", &n) != EOF){
    v.clear();
    for(i = 0 ; i < n; i++){
      scanf("%d", &num);
      v.push_back(num);
    }
    sort(v.begin(), v.end());
    for(i = 0; i < v.size(); i++){
      printf("%04d\n", v[i]);
    }
  }
  return 0;
}
