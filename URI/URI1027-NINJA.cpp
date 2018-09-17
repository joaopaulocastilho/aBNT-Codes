#include <bits/stdc++.h>

using namespace std;

const int MAX = 1123;

typedef pair<int, int> ii;

int n, memo[MAX][MAX][2];
vector<ii> points;

int pd(int i, int pai,  int sobe){
  int x = points[pai].first, y = points[pai].second;
  int newx = points[i].first, newy = points[i].second;
  if(i == n) return 1;
  if(memo[i][pai][sobe] != -1) return memo[i][pai][sobe];
  if(!(newx > x) || (abs(y - newy) != 2) || (sobe && newy < y) || (!sobe && newy > y))
    return memo[i][pai][sobe] = pd(i+1, pai, sobe);
  return memo[i][pai][sobe] = max(pd(i+1, pai, sobe), pd(i+1, i, !sobe) + 1);
}

int main(void){
  int i, x, y, ans;

  while(scanf("%d", &n) != EOF){
    points.clear();
    memset(memo, -1, sizeof(memo));
    for(i = 0; i < n; i++){
      scanf("%d %d", &x, &y);
      points.push_back(ii(x, y));
    }
    sort(points.begin(), points.end());
    for(ans = i = 0; i < n; i++){
      ans = max(ans, max(pd(i, i, 0),
			 pd(i, i, 1)));
    }
      printf("%d\n", ans);
  }
  return 0;
}
