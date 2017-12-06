#include <cstdio>

int main(void){
  int a[3], b[3], i, j, idx, menor, aux;

  scanf("%d %d %d", &a[0], &a[1], &a[2]);
  b[0] = a[0]; b[1] = a[1]; b[2] = a[2];
  for(i = 0; i < 3; i++){
    idx = i;
    menor = 999999999;
    for(j = i; j < 3; j++)
      if(b[j] < menor){ menor = b[j]; idx = j; }
    if(idx != i){
      aux = b[i];
      b[i] = menor;
      b[idx] = aux;
    }
  }
  for(i = 0; i < 3; i++) printf("%d\n", b[i]);
  printf("\n");
  for(i = 0; i < 3; i++) printf("%d\n", a[i]);
  return 0;
}
