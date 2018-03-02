#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void){
  int tc, count, num;
  vector<int> coins;
  double sum = 0;
  count = 0;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d", &num);
    coins.push_back(num);
    sum += num;
    count++;
  }
  sort(coins.begin(), coins.end());
  int qtd = 0, ccount = 0;
  for(int i = count-1; i >= 0; i--){
    if(qtd > sum) break;
    qtd += coins[i];
    sum -= coins[i];
    ccount++;
  }
  printf("%d", ccount);
  printf("\n");
  return 0;
}
