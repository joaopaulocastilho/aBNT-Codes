#include <cstdio>

int main(void){
  int linhas;
  scanf("%d", &linhas);
  for(int i = 0, j = 1; i < linhas; i++, j+=4){
    for(int k = 0; k < 3; k++)
      printf("%d ", j+k);
    printf("PUM\n");
  }
  return 0;
}
