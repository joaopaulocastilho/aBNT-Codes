#include <cstdio>
#include <math.h>

using namespace std;

#define MAX 1123

int PI[MAX];
int pi;

void crivo(int n) {
  int i, j, primo, raiz;
  PI[0] = 2; pi = 1;
  for (i = 3; i <= n; i++) {
    primo = 1; raiz = sqrt(i);
    for (j = 0; primo && j < pi && PI[j] <= raiz; j++)
      if (i % PI[j] == 0) primo = 0;
    if (primo) PI[pi++] = i;
  }
}

int main(void){
  int a;
  scanf("%d", &a);
  crivo(a);
  for(int i = 0; i < pi; i++){
    printf("%d", PI[i]);
    if(i != (pi - 1)) printf(" ");
  }
  printf("\n");
  return 0;
}
