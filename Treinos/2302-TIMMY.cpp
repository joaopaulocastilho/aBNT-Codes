#include <cstdio>
#include <string.h>

int main(void){
  int ct, n, m, px = 0, py = 0, dir, mx, my, count = 0;
  //memset(matrix, 0, sizeof(matrix));
  scanf("%d %d", &n, &m);
  scanf("%d %d", &mx, &my);
  scanf("%d", &ct);
  for(int i = 0; i <= ct; i++){
    if((mx == px && my == py) ||
       (mx-1 == px && my == py) ||
       (mx == px && my+1 == py) ||
       (mx-1 == px && my+1 == py) ||
       (mx == px && my+2 == py) ||
       (mx-1 == px && my+2 == py) ||
       (mx == px && my-1 == py) ||
       (mx-1 == px && my-1 == py) ||
       (mx-2 == px && my == py) ||
       (mx-2 == px && my+1 == py) ||
       (mx+1 == px && my == py) ||
       (mx+1 == px && my+1 == py)) count++;
    scanf("%d", &dir);
    if(dir == 1) py++;
    if(dir == 2) py--;
    if(dir == 3) px++;
    if(dir == 4) px--;
  }
  printf("%d\n", count);
  return 0;
}
