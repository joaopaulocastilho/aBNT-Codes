#include <stdio.h>

#define MAX 112

int main(void){
  int n, i, si, bi;
  double diff, gd[7], sg, bg, ttl;
  char name[MAX];

  scanf("%d", &n);
  while(n--){
    sg = 11; bg = -1; ttl = 0;
    scanf("%s\n", name);
    scanf("%lf", &diff);
    for(i = 0; i < 7; i++){
      scanf("%lf", &gd[i]);
      if(gd[i] > bg){ bg = gd[i]; bi = i;}
      if(gd[i] < sg){ sg = gd[i]; si = i;}
    }
    for(i = 0; i < 7; i++)
      if(i != si && i != bi) ttl += gd[i];
    printf("%s %.2lf\n", name, ttl * diff);
  }

  return 0;
}
