#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 11234

int main(void){
  int i, n, v[MAX], seq, ans = -1;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &v[i]);
  for(seq = 1, i = 1; i < n; i++){
    if(v[i] == v[i-1]) seq++;
    else{
      ans = max(ans, seq);
      seq = 1;
    }
  }
  printf("%d\n", max(ans, seq));

  return 0;
}
