#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

#define MAX 112345

int main(void){
  int tc, n, v[MAX], done;

  scanf("%d", &tc);
  for(int i = 1; i <= tc; i++){
    printf("Case #%d: ", i);
    scanf("%d", &n);
    for(int j = 0; j < n; j++){
      scanf("%d", &v[j]);
    }
    done = 0;
    while(!done){
      done = 1;
      for(int j= 0; j < n-2; j++){
	if(v[j] > v[j+2]){
	  done = 0;
	  swap(v[j], v[j+2]);
	}
      }
    }
    int flag = 0;
    for(int j = 0; j < n-1; j++) if(v[j] > v[j+1]){ printf("%d\n", j); flag = 1; break; }
    //for(int j = 0; j < n; j++) printf("%d ", v[j]); printf("\n");
    if(flag) continue;
    printf("OK\n");
  }
  return 0;
}
