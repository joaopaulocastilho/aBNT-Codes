#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int n, m, fig, bog[MAX];

  memset(bog, 0, sizeof(bog));
  scanf("%d %d", &n, &m);
  while(m--){
    scanf("%d", &fig);
    if(!bog[fig]) n--;
    bog[fig] = 1;
  }
  printf("%d\n", n);
  
  return 0;
}
