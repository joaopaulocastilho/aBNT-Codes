#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 21
#define INF 1123456789

int s, d, year[MAX], ans;

void bt(int i, int ttl){
  int j, acum, off;
  for(off = acum = j = 0; j < i; j++){
    acum += year[j] ? s : d;
    if(j > 4) acum -= year[off++] == 1 ? s : d;
    if(j >= 4 && acum > 0) return;
  }
  if(i == 12) { ans = max(ans, ttl); return; }
  year[i] = 1; bt(i+1, ttl + s);  
  year[i] = 0; bt(i+1, ttl + d);
}

int main(void){
  
  while(scanf("%d %d", &s, &d) != EOF){
    d = -d; ans = -INF;
    bt(0, 0);
    if(ans >= 0)printf("%d\n", ans);
    else printf("Deficit\n");
  }

  return 0;
}
