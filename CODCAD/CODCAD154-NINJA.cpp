#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
  int num, maior = -1;

  while(scanf("%d", &num), num)
    maior = max(maior, num);
  printf("%d\n", maior);

  return 0;
}
