#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> ii;

int main(void){
  int i, j, sum, n, m, num;
  vector<ii> times;
  
  scanf("%d %d", &n, &m);
  for(i = 0; i < n; i++){
    for(sum = j = 0; j < m; j++){
      scanf("%d", &num);
      sum += num;
    }
    times.push_back(ii(sum, i+1));
  }
  sort(times.begin(), times.end());
  for(i = 0; i < 3; i++)
    printf("%d\n", times[i].second);
  
  return 0;
}
