#include <bits/stdc++.h>

const int MAX = 1123;

int main(void){
  int i, n, size, ans, first, nums[MAX];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &nums[i]);
    if(nums[i] == 1) ans++;
  }
  printf("%d\n", ans);
  for(first = size = i = 1; i < n; i++){
    if(nums[i] == 1){
      printf("%s%d", first ? "" : " ", size);
      size = 1;
      first = 0;
    }
    else size++;
  }
  printf(" %d\n", size);

  return 0;
}
