#include <cstdio>

int main(void){
  int v1, v2;
  while(scanf("%d %d", &v1, &v2), v1 != 0 && v2 != 0)
    if(v1 > 0 && v2 > 0) printf("primeiro\n");
    else if(v1 > 0 && v2 < 0) printf("quarto\n");
    else if(v1 < 0 && v2 < 0) printf("terceiro\n");
    else if(v1 < 0 && v2 > 0) printf("segundo\n");
  return 0;
}
