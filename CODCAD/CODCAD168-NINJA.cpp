#include <bits/stdc++.h>

const int MAX = 

int box[MAX];

int dp(int i, int res){
  if(i < 0) return -1;
}

int main(void){
  int i, n;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d %d", &box[i].second, &box[i].first);
    box[i].first -= box[i].second;
  }
  sort(box, box + n);
  printf("%d\n", pd(n-1, box[n-1].first);)
  
  return 0;
}
