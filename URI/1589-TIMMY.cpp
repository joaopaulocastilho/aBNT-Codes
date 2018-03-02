#include <cstdio>

int main(void){
  int tc, r1, r2;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d %d", &r1, &r2);
    printf("%d\n", r1+r2);
  }
  return 0;
}
