#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n, m, myx, myy, ax, ay, tmp;

  while(scanf("%d %d", &n, &m) != EOF){
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++){
        scanf("%d", &tmp);
        if(tmp == 1){
          myx = i;
          myy = j;
        }
        else if(tmp == 2){
          ax = i;
          ay = j;
        }
      }
    printf("%d\n", abs(myx-ax) + abs(myy-ay));
  }
  return 0;
}
