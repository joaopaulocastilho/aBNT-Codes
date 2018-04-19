#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 412345

int bit[MAX], n, m;

void put(int x, int val) for(; x <= n; x+= x&-x) bit[x] += val;

void update(int x, int val) for(; x <= n; x += x&-x) bit[x] -= val;

int query(int x){
  int sum = 0;
  for(; x > 0; x -= x&-x) sum += bit[x];
  return sum;
}

int main(void){
  int num[MAX], awoken[MAX];
  scanf("%d %d", &n, &m);
  memset(bit, 0, sizeof(bit));
  int ans = 0;
  for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
  for(int i = 1; i <= n; i++) scanf("%d", &awoken[i]);
  for(int i = 1; i <= n; i++)
    if(awoken[i] == 0)
      put(i, num[i]);
    else ans += num[i];
  int dif = 0;
  for(int i = n; i >= m; i--){
    dif = max((query(i) - query(i-m)), dif);
  }
  printf("%d\n", dif + ans);
  return 0;
}
