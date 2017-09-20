#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void){
  int J, R, pts[MAX], num, i, k, maior=0, iv;
  scanf("%d%d", &J, &R);
  memset(pts, 0, sizeof(pts));
  for(i=0, k=0; i<J*R; i++){
    scanf("%d", &num);
    pts[++k]+=num;
    if(k==J) k=0;
  }
  for(i=1; i<=J; i++){
    if(maior<=pts[i]){ maior=pts[i]; iv=i; }
  }
  printf("%d\n", iv);
  return 0;
}
