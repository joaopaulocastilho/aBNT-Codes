#include <stdio.h>
#include <string.h>

#define MAXC 300
#define MAX 11234

int main(void){
  int i, n, k, m, end, val, ans, qtd[MAXC], value[MAXC];
  char c, line[MAX];

  scanf("%d ", &n);
  while(n--){
    memset(qtd, 0, sizeof(qtd));
    memset(value, 0, sizeof(value));
    scanf("%d ", &k);
    while(k--){
      scanf("%c %d ", &c, &val);
      value[c] = val;
    }
    scanf("%d ", &m);
    while(m--){
      fgets(line, MAX, stdin);
      end = strlen(line);
      for(i = 0; i < end-1; i++)
	if(line[i] >= 1 && line[i] <= MAXC) qtd[line[i]]++;
    }
    for(ans = i = 0; i < MAXC; i++) ans += qtd[i] * value[i];
    printf("%d.%.2d$\n", ans/100, ans%100);
  }
  
  return 0;
}
