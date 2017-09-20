#include <stdio.h>

int main(void){
  int t, b, i;
  double dab[4], gua[4];

  scanf("%d", &t);
  while(t--){
    scanf("%d", &b);
    for(i = 0; i < 3; i++) scanf("%lf", &dab[i]);
    for(i = 0; i < 3; i++) scanf("%lf", &gua[i]);
    dab[3] = ((dab[0] + dab[1])/2) + (((int)dab[2]) % 2 ? 0 : b);
    gua[3] = ((gua[0] + gua[1])/2) + (((int)gua[2]) % 2 ? 0 : b);
    if(dab[3] > gua[3]) printf("Dabriel\n");
    else if(dab[3] < gua[3]) printf("Guarte\n");
    else printf("Empate\n");
  }

  return 0;
}
