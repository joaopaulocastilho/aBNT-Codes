#include <cstdio>

int main(void){
  int n, num, ant, count, maior;
  scanf("%d", &n);
  count = 0;
  maior = -1;
  ant = -1;
  while(n--){
    scanf("%d", &num);    
    if(num >= ant) count++;
    else{
      if(count > maior) maior = count;
      count = 1;
    }
    if(count > maior) maior = count;
    ant = num;     
  }
  printf("%d\n", maior);
  return 0;
}
