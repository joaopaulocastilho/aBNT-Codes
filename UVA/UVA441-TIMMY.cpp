#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int main(void){
  int n, num, first = 1;
  vector<int> v;
  while(scanf("%d", &n), n != 0){
    if(!first) printf("\n");
    first = 0;
    v.clear();
    for(int i = 0; i < n ; i++){
      scanf("%d", &num);
      v.push_back(num);
    }
    for(int i = 0; i < n-5; i++){
      for(int j = i+1; j < n-4; j++)
	for(int k = j+1; k < n-3; k++)
	  for(int l = k+1; l < n-2; l++)
	    for(int m = l+1; m < n-1; m++)
	      for(int o = m+1; o < n; o++)
		printf("%d %d %d %d %d %d\n",
		       v[i], v[j], v[k], v[l], v[m], v[o]);
    }
  }
  return 0;
}
