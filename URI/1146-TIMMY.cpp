#include <cstdio>

int main(void){
  int count;
  while(scanf("%d", &count), count != 0)
    for(int i = 1; i <= count; i++){
      printf("%d", i);
      printf("%c", i == count ? '\n' : ' ');
    }
  return 0;
}
