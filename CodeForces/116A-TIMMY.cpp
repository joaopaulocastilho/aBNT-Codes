#include <cstdio>

int main(void){
  int n, a, b, dentro = 0, maior = -1;
  scanf("%d", &n);
  while(n--){
    scanf("%d %d", &a, &b);
    dentro -= a;
    dentro += b;
    if(dentro > maior) maior = dentro;
  }
  printf("%d\n", maior);
}
