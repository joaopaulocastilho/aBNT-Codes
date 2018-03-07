#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int i, n, num, big, last, ans;
  vector <int> pop;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &num);
    pop.push_back(num); 
  }
  sort(pop.begin(), pop.end());
  last = pop.size() - 1;
  big = pop[last];
  for(ans = 0, i = last; i >= 0; i--){
    if(pop[i] < big) ans += big - pop[i];
  }
  printf("%d\n", ans);
  
  return 0;
}
