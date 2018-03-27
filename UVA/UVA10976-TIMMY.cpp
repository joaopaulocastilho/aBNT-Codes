#include <cstdio>
#include <vector>
#include <utility>

using namespace std;


#define MAX 10000
#define eps 10e-9
#define INF 112345678

int main(void){
  double ans;
  int resp, n;
  vector< pair<int, int> > v;
  while(scanf("%d", &n) != EOF){
    v.clear();
    resp = 0;
    int flag = 1;
    ans = INF;
    for(int y = n+1; flag; y++){
      ans = (n*((double)y))/(((double)y) - n);
      if((ans - (int)ans <= eps) && y <= ans){ 
	v.push_back(make_pair((int)ans, (int)y)); 
	resp++;
      }
      if(y > ans) flag = 0;
    }
    printf("%d\n", resp);
    for(int i = 0; i < v.size(); i++){
      printf("1/%d = 1/%d + 1/%d\n", n, v[i].first, v[i].second);
    }
  }
  return 0;
}
