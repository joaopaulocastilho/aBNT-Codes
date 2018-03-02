#include <cstdio>

int main(void){
  int valor, tc;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d", &valor);
    if(valor % 2 == 0)
      if(valor > 0) printf("EVEN POSITIVE\n");
      else if(valor == 0) printf("NULL\n");
      else printf("EVEN NEGATIVE\n");
    else if(valor > 0) printf("ODD POSITIVE\n");
      else printf("ODD NEGATIVE\n");
  }
  return 0;
}
