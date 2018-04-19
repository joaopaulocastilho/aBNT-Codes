#include <cstdio>
#include <cstring>

#define MAX 1123456
#define LIM 1000000
int main(void){
  int v[MAX], n, m, s, e, r, flag;
  while(scanf("%d %d", &n, &m), n + m != 0){
    flag = 0;
    memset(v, 0, sizeof(v));
    while(n--){
      scanf("%d %d", &s, &e);
      for(int i = s; i < e && !flag; i++){
	if(!v[i]) v[i] = 1;
	else{ printf("CONFLICT\n"); flag = 1; }
      }
    }
    while(m--){
      scanf("%d %d %d", &s, &e, &r);
      while(s <= LIM && !flag){
	for(int i = s; i < e && !flag; i++){
	  if(!v[i]) v[i] = 1;
	  else{ printf("CONFLICT\n"); flag = 1; }
	}
	s += r; e += r;
      }
    }
    if(!flag) printf("NO CONFLICT\n");
  }
  return 0;
}
