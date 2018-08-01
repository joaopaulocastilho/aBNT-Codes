#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int i, n, num;
  vector<int> v;
  
  scanf("%d", &n);
  while(n--){
    scanf("%d", &num);
    v.push_back(num);
  }
  sort(v.begin(), v.end());
  for(i = 0; i < v.size(); i++)
    printf("%s%d", i ? " " : "", v[i]);
  
  return 0;
}
