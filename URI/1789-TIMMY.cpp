#include <cstdio>

int main(void){
  int maior, n, l;
  while(scanf("%d", &n) != EOF){
    maior = -1;
    while(n--){
      scanf("%d", &l);
      if(l > maior) maior = l;
    }
    printf("%s\n", maior >= 20 ? "3" : (maior >= 10 ? "2" : "1"));
  }
  return 0;
}
