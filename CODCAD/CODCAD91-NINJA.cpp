#include <stdio.h>

int main(void){
  int h, p, f, d;

  scanf("%d %d %d %d", &h, &p, &f, &d);

  if(d == 1){
    if(h > f && (p < f || p > h)) printf("S\n");
    else if(h < f && p > h && p < f) printf("S\n");
    else printf("N\n");
  }
  else{
    if(h < f && (p > f || p < h)) printf("S\n");
    else if(h > f && p < h && p > f) printf("S\n");
    else printf("N\n");
  }

  return 0;
}
