#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int n, min = 1, num, i;
  vector<int> v;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &num);
    v.push_back(num);
  }
  sort(v.begin(), v.end());

  while(v.size() > 1){
    if(min) v.erase(v.begin() + v.size()-1);
    else v.erase(v.begin());
    min ^= 1;
  }
  printf("%d\n", v[0]);
  
  return 0;
}
