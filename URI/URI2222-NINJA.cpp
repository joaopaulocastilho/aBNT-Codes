#include <stdio.h>
#include <string.h>

#define MAXC 11234
#define MAXI 112

int main(void){
  int t, n, i, j, q, ans, op, conj1, conj2, tmp, sets[MAXC][MAXI];

  scanf("%d", &t);
  while(t--){
    memset(sets, 0, sizeof(sets));
    scanf("%d", &n);
    for(i = 0; i < n; i++){
      scanf("%d", &sets[i][0]);
      for(j = 1; j <= sets[i][0]; j++){
        scanf("%d", &tmp);
        sets[i][tmp] = 1;
      }
    }
    scanf("%d", &q);
    while(q--){
      ans = 0;
      scanf("%d %d %d", &op, &conj1, &conj2);
      conj1--; conj2--;
      for(i = j = 1; i < MAXI; i++, j++){
        if(op == 1 && (sets[conj1][i] && sets[conj2][j])) ans++;
        else if(op == 2 && (sets[conj1][i] || sets[conj2][j])) ans++;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
