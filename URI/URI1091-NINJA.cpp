#include<bits/stdc++.h>

int main(void){
  int n, px, py, x, y;

  while(scanf("%d", &n), n){
    scanf("%d %d", &px, &py);
    while(n--){
      scanf("%d %d", &x, &y);
      if(x == px || y == py) printf("divisa\n");
      else if(x > px && y > py) printf("NE\n");
      else if(x < px && y < py) printf("SO\n");
      else if(x < px && y > py) printf("NO\n");
      else printf("SE\n");
    }
  }

  return 0;
}
