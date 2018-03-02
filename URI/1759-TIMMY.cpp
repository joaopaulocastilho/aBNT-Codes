#include <cstdio>

int main(void){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    printf("Ho");
    printf("%s", i != n-1 ? " " : "");
  }
  printf("!\n");
  return 0;
}
