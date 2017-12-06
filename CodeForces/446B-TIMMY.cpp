#include <cstdio>

#define MAX 1123456

int main(void){
  int n, remaining = 0, guilty[MAX];
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &guilty[i]);
  }
  for(int i = n-1; i >= 0; i--){
    if(remaining){ remaining--; n--; }
    if(guilty[i] > remaining)
      remaining = guilty[i];
  }
  printf("%d\n", n);
  return 0;
}
