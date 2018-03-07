#include <stdio.h>

int main(void){
  int n, mt, ct, m, c; 

  mt = ct = 0;
  scanf("%d", &n);
  while(n--){
    scanf("%d %d", &m, &c);
    if(m > c) mt++;
    else if(c > m) ct++;
  }
  if(ct > mt) printf("Chris\n");
  else if(mt > ct) printf("Mishka\n");
  else printf("Friendship is magic!^^\n");

  return 0;
}
