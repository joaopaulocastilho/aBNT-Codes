#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 1123
#define INF 112345678
#define EPS 10e-9

int main(void){
  int i, j, f, r;
  double fteeth[MAX], rteeth[MAX], ans;
  vector <double> ratios;
  
  while(scanf("%d", &f), f){
    scanf("%d", &r);
    for(i = 0; i < f; i++) scanf("%lf\n", &fteeth[i]); 
    for(i = 0; i < r; i++) scanf("%lf\n", &rteeth[i]);
    for(i = 0; i < f; i++)
      for(j = 0; j < r; j++)
	ratios.push_back(rteeth[j]/fteeth[i]);
    sort(ratios.begin(), ratios.end());
    //for(i = 0; i < ratios.size(); i++) printf("%lf \n", ratios[i]); printf("\n");
    for(ans = 0, i = 1; i < ratios.size(); i++)
      if(ratios[i]/ratios[i-1] - ans > EPS)
	ans = ratios[i]/ratios[i-1];
    printf("%.2lf\n", ans);
    ratios.clear();
  }
  
  return 0;
}
