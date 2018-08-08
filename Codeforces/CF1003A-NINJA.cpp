#include <bits/stdc++.h>

using namespace std;

const int MAX = 112;

int coins[MAX];

int main(void){
  int n, num, ans = 1;
  
  scanf("%d", &n);
  while(n--){
    scanf("%d", &num);
    coins[num]++;
    ans = max(ans, coins[num]);
  }
  printf("%d\n", ans);

  return 0;
}
