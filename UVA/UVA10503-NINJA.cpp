#include <stdio.h>
#include <string.h>

#define MAX 21

typedef struct{
  int l, r;
}piece_t;

int ans, n, m, used[MAX];
piece_t spaces[MAX], pieces[MAX];

void bt(int i){
  int k;

  //for(k = 0; k < i; k++) printf("%d-%d ", spaces[k].l, spaces[k].r); printf("\n");
  
  if(i == n+1 && spaces[i].l == spaces[i-1].r){ans = 1; return;}
  for(k = 0; k < m; k++)
    if(!used[k] && pieces[k].l == spaces[i-1].r){
      used[k] = 1; spaces[i] = pieces[k];
      bt(i+1);
      used[k] = 0;
    }
    else if(!used[k] && pieces[k].r == spaces[i-1].r){
      used[k] = 1;
      spaces[i].l = pieces[k].r; spaces[i].r = pieces[k].l;
      bt(i+1);
      used[k] = 0;
    }
}

int main(void){
  int i;

  memset(used, 0, sizeof(used));
  while(scanf("%d", &n), n){
    scanf("%d", &m);
    scanf("%d %d", &spaces[0].l, &spaces[0].r);
    scanf("%d %d", &spaces[n+1].l, &spaces[n+1].r);
    for(ans = i = 0; i < m; i++) scanf("%d %d", &pieces[i].l, &pieces[i].r);
    //printf("INITIALS: %d-%d %d-%d\n", spaces[0].l, spaces[0].r, spaces[n+1].l, spaces[n+1].r);
    bt(1);
    printf("%s\n", ans ? "YES" : "NO");
  }

  return 0;
}
