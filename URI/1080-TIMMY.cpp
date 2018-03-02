#include <cstdio>

#define MAX 112

int main(void){
  int valor[MAX], maior = -1, idx;
  for(int i = 0; i < 100; i++){
    scanf("%d", &valor[i]);
    if(valor[i] > maior){ maior = valor[i]; idx = i; }
  }
  printf("%d\n%d\n", maior, idx+1);
  return 0;
}
