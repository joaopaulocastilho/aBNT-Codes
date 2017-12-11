#include <stdio.h>

int main(void){
  int t, n, m, x, y;

  while(scanf("%d", &t), t){
    scanf("%d %d", &n, &m);
    while(t--){
      scanf("%d %d", &x, &y);
      if(x == n || y == m) printf("divisa\n");
      else if(y > m) printf("%s\n", x > n ? "NE" : "NO");
      else printf("%s\n", x > n ? "SE" : "SO");
    }
  }
}
