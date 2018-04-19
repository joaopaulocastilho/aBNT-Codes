#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX 112

int main(void){
  int sub, num, aux, sz;
  scanf("%d", &num);
  int count = 1;
  while(num != 0){
    aux = num;
    sz = 0;
    sub = 0;
    while(aux > 9){
      sub += aux % 10;
      aux = aux/10;
      sz++;
    }
    sub += aux;
    num -= sub;
    count++;
  }
  printf("%d\n", count);
  return 0;
}
