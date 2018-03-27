#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define INF 112345678
#define MAX 1123

int main(void){
  int caso = 1, n, m, sum, num;
  int v[MAX];
  while(scanf("%d", &n), n != 0){
    printf("Case %d:\n", caso++);
    for(int i = 0; i < n; i++){
      scanf("%d", &v[i]);
    }
    scanf("%d", &m);
    while(m--){
      sum = INF;
      scanf("%d", &num);
      for(int i = 0; i < n; i++){
	for(int j = 0; j < n; j++){
	  if(i == j) continue;
	  if(abs(sum-num) > abs(v[i] + v[j] - num))
	    sum = v[i] + v[j];
	}
      }
      printf("Closest sum to %d is %d.\n", num, sum);
    }
  }

  return 0;
}
