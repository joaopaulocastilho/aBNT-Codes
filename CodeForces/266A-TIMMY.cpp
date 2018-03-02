#include <cstdio>

int main(void){
  int n, count = 0;
  char str[51];
  scanf("%d", &n);
  getchar();
  for(int i = 0; i < n; i++){
    scanf("%c", &str[i]);
    if(i && str[i] == str[i-1]) count++;
  }
  printf("%d\n", count);
  return 0;
}
