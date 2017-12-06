#include <cstdio>

#define MAX 1123

int main(void){
  int i, v[MAX], count5 = 0, count0 = 0, count = 0, n, num;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &num);
    if(num == 5) count5++;
    else count0++;
  }
  if(!count0) printf("-1\n");
  else if(count5 < 9) printf("0\n");
  else{
    count5 -= count5 % 9;
    for(int i = 0; i < count5; i++) printf("5");
    for(int i = 0; i < count0; i++) printf("0");
    printf("\n");
  }
  return 0;
}
