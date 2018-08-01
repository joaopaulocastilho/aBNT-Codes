#include <stdio.h>
#include <string.h>

#define MAX 1123456
#define LIM 1000000

int time[MAX];

int main(void){
  int conf, i, j, k, p, n, m, s, e;

  while(scanf("%d %d", &n, &m), n || m){
    memset(time, 0, sizeof(time));
    conf = 0;
    while(n--){
      scanf("%d %d", &s, &e);
      for(i = s; i < e && !conf; i++){
	if(time[i]) conf = 1;
	time[i] = 1;
      }
    }
    while(m--){
      scanf("%d %d %d", &s, &e, &p);
      for(i = s, j = e; i <= LIM && !conf; i += p, j += p)
	for(k = i; k < j && !conf; k++){
	  if(time[k]) conf = 1;
	  time[k] = 1;
	}
    }
    printf("%sCONFLICT\n", !conf ? "NO " : "");
  }

  return 0;
}
