#include <cstdio>

int main(void){
  int n, a, l;
  scanf("%d", &n);
  while(n--){
    scanf("%d %d", &a, &l);
    printf("%d\n", (a/3) * (l/3));
  }

  return 0;
}
