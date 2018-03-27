#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int i, n, num, ans, total, taken;
  vector <int> coins;

  scanf("%d", &n);
  for(ans = total = taken = i = 0; i < n; i++){
    scanf("%d", &num);
    total += num;
    coins.push_back(num);
  }
  sort(coins.begin(), coins.end());
  for(i = coins.size() - 1; i >= 0; i--)
    if(taken <= total){
      taken += coins[i];
      total -= coins[i];
      ans++;
    }
  printf("%d\n", ans);
  return 0;
}
