#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define EPS 10e-9

int main(void){
  vector<double> vn;
  vector<double> vm;
  vector<double> vans;
  double ans, num;
  int n, m;
  while(scanf("%d", &n), n != 0){
    vn.clear();
    vm.clear();
    vans.clear();
    ans = 0;
    scanf("%d", &m);
    for(int i = 0; i < n; i++){
      scanf("%lf", &num);
      vn.push_back(num);
    }
    for(int i = 0; i < m; i++){
      scanf("%lf", &num);
      vm.push_back(num);
    }
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
	vans.push_back(vm[j]/vn[i]);
    sort(vans.begin(), vans.end());
    for(int i = 0; i < n*m-1; i++){
      if(vans[i+1]/vans[i] > ans) ans = vans[i+1]/vans[i];
    }
    printf("%.2lf\n", ans);
  }
  return 0;
}
