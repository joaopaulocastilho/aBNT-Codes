#include <stdio.h>

#define MAX 1123
#define empty(x, y) (x == 'O' && y == 'O')

int main(void){
  char bus[MAX][10];
  int i, rows, flag = 0;

  scanf("%d ", &rows);
  for(i = 0; i < rows; i++) scanf("%s", bus[i]);
  for(i = 0; i < rows; i++){
    if(empty(bus[i][0], bus[i][1])){ bus[i][0] = bus[i][1] = '+'; flag = 1; break; }
    if(empty(bus[i][3], bus[i][4])){ bus[i][3] = bus[i][4] = '+'; flag = 1; break; }
  }
  if(flag){
    printf("YES\n");
    for(i = 0; i < rows; i++) printf("%s\n", bus[i]);
  }
  else printf("NO\n");
  return 0;
}
