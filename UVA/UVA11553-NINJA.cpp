#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 1123456789
#define MAX 11

int main(void){
  int i, j, t, n, ans, curr, m[MAX][MAX];

  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    vector<int> rows;
    for(ans = INF, i = 0; i < n; i++) rows.push_back(i);
    for(i = 0; i < n; i++)
      for(j = 0; j < n; j++) scanf("%d", &m[i][j]);
    do{
      for(curr = i = 0; i < n; i++) curr += m[i][rows[i]];
      ans = min(curr, ans);
    }while(next_permutation(rows.begin(), rows.end()));
    printf("%d\n", ans);
  }

  return 0;
}
