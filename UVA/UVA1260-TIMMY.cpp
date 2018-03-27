#include <cstdio>

#define MAX 1123

int main(void){
  int n, tc, v[MAX], count = 0, ans;
  scanf("%d", &tc);
  while(tc--){
    ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    for(int i = 1; i < n; i++){
      count = 0;
      for(int j = i-1, k = i; j >= 0; j--)
	if(v[j] <= v[k]) count++;
      ans += count;
    }
    printf("%d\n", ans);
  }
  return 0;
}
  
