#include <cstdio>

int main(void){
  int w, h, l, n;
  scanf("%d\n%d", &l, &n);
  while(n--){
    scanf("%d %d", &w, &h);
    if(w >= l && h >= l){
      if(w == h) printf("ACCEPTED\n");
      else printf("CROP IT\n");
    }
    else printf("UPLOAD ANOTHER\n");
  }
  return 0;
}
