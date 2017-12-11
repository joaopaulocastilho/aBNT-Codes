#include <stdio.h>
#include <string.h>

#define INF 1123456789
#define MAX 112

int main(void){
  int n, p, i, reqmet, newreq, first = 1, cas = 1;
  double best, newval;
  char ans[MAX], garb[MAX], str[MAX];
  
  while(scanf("%d %d ", &n, &p), n || p){
    best = INF; reqmet = 0;
    for(i = 0; i < n; i++) fgets(garb, MAX, stdin);
    while(p--){
      fgets(str, MAX, stdin);
      scanf("%lf %d ", &newval, &newreq);
      for(i = 0; i < newreq; i++) fgets(garb, MAX, stdin);
      if(newreq > reqmet || (newreq == reqmet && newval < best)){
	reqmet = newreq;
	best = newval;
	strcpy(ans, str);
      }
    }
    if(first) first = 0;
    else printf("\n");
    printf("RFP #%d\n", cas++);
    printf("%s", ans);
  }
  return 0;
}
