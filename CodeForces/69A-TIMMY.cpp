#include <cstdio>

int main(void){
  int a, b, c, x=0, y=0, z=0, n;
  scanf("%d", &n);
  while(n--){
    scanf("%d %d %d", &a, &b, &c);
    x += a;
    y += b;
    z += c;
  }
  if(x || y || z || x < 0 || y < 0 || z < 0) printf("NO\n");
  else printf("YES\n");
  return 0;
}
