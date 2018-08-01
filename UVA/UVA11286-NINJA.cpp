#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main(void){
  int i, j, n, num, ans, big;
  
  while(scanf("%d", &n), n){
    map<vi, int> combs;
    for(big = -1, ans = 0, i = 0; i < n; i++){
      vi vec;
      for(j = 0; j < 5; j++){
	scanf("%d", &num);
	vec.push_back(num);
      }
      sort(vec.begin(), vec.end());
      if(combs.find(vec) == combs.end()) combs[vec] = 1;
      else combs[vec]++;
    }
    for(map<vi,int>::iterator it = combs.begin(); it != combs.end(); it++) big = max(it->second, big);
    for(map<vi,int>::iterator it = combs.begin(); it != combs.end(); it++) if(it->second == big) ans += big;
    printf("%d\n", ans);
  }

  return 0;
}
