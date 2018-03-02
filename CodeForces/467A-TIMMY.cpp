#include <cstdio>

int main(void){
  int tc, a, b;
  int count = 0;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d %d", &a, &b);
    if(b - a >= 2) count++;
  }
  printf("%d\n", count);
  return 0;
}
