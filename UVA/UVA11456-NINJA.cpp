#include <bits/stdc++.h>

using namespace std;

const int MAX = 2123;

int n, v[MAX], memo[MAX][MAX], lis[MAX], lds[MAX];

int main(void){
  int i, j, t, ans;
  
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &v[i]);
    //LIS
    for(i = n-1; i >= 0; i--)
      for(lis[i] = 1, j = i+1; j < n; j++)
	if(v[i] < v[j]) lis[i] = max(lis[i], lis[j] + 1);
    //LDS
    for(i = n-1; i >= 0; i--)
      for(lds[i] = 1, j = i+1; j < n; j++)
	if(v[i] > v[j]) lds[i] = max(lds[i], lds[j] + 1);

    //for(i = 0; i < n; i++) printf("%d ", lis[i]); printf("\n");
    //for(i = 0; i < n; i++) printf("%d ", lds[i]); printf("\n");

    for(ans = i = 0; i < n; i++) ans = max(ans, lis[i] + lds[i] - 1);
    printf("%d\n", ans);
  }

  return 0;
}
