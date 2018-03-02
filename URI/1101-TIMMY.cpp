#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){
  int valor1, valor2, count;
  while(scanf("%d %d", &valor1, &valor2), valor1 > 0 && valor2 > 0){
    count = 0;
    if(valor1 > valor2) swap(valor1, valor2);
    for(int i = valor1; i <= valor2; i++){
      printf("%d ", i);
      count+= i;
    }
    printf("Sum=%d\n", count);
  }
  return 0;
}
