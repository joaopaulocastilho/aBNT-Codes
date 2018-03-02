#include <cstdio>
#include <cstring>

#define MAXM 33
#define MAXN 34

int vm[MAXM];
int vn[MAXN];
int pos = 0;

void binario(int m){
  while(m != 0 && m != 1){
    vm[pos++] = m % 2;
    m = m / 2;
  }
  vm[pos] = m;
}

int main(void){
  int n, m, ans = 0;
  memset(vm, 0, sizeof(vm));
  scanf("%d %d", &n, &m);
  binario(m);
  if(n > pos){ printf("%d\n", m); return 0; }
  // for(int i = 0; i < MAXM; i++)
    // printf("%d", vm[i]);
  //printf("\n");
  for(int i = 0, j = 1; i < n; i++, j *= 2){
    ans += (vm[i] == 1 ? j : 0);
    // printf("%d\n", ans);
  }
  printf("%d\n", ans);
  return 0;
}
