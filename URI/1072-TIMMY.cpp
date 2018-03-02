#include <cstdio>

int main(void){
  int tc, valor, in = 0, out = 0; 
  scanf("%d", &tc);
  while(tc--){
    scanf("%d", &valor);
    if(valor >= 10 && valor <= 20) in++;
    else out++;
  }
  printf("%d in\n", in);
  printf("%d out\n", out);
  return 0;
}
