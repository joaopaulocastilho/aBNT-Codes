/* \ */
#include <stdio.h>
#include <stdlib.h>

int main(void){
  int h1, m1, h2, m2, a;
  scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
  while(h1 != 0 || h2 != 0 || m1 != 0 || m2 != 0){
    if(h2 <= h1 && m2 < m1){
      a = (h2 + 24 - h1)*60 + (m2-m1);
    }
    else if(h2 == 0){
      h2 = 24;
      a = (h2 - h1)*60 + (m2-m1);
    }
    else if(h1 > h2 && m2 > m1){
      a = 24*60 - ((h1*60 - h2*60) - (m2 - m1));
    }
    else{
      a = (h2 - h1)*60 + (m2-m1);
    }
    printf("%d\n", a);
    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
  }
  return 0;
}
