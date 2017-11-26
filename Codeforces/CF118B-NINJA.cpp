#include <stdio.h>

int main(void){
  int n, i, j, first, num, lines, spaces;

  scanf("%d", &n);
  lines = 2*n+1;
  for(i = 0; i < lines; i++){
    first = 1;
    spaces = i < n ? n-i : i-n;
    num = n - spaces + 1;
    for(j = 0; j < spaces; j++) printf("  ");
    for(j = 0; j < num; j++){
      if(first) first = 0;
      else printf(" ");
      printf("%d", j);
    }
    for(j = num - 2; j >= 0; j--) {
      if(first) first = 0;
      else printf(" ");
      printf("%d", j);
    }
    printf("\n");
  }
  return 0;
}
