#include <cstdio>

int main(void){
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  if(a + b > n) printf("Deixa para amanha!\n");
  else printf("Farei hoje!\n");
  return 0;
}
