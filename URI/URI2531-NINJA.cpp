#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

#define MAX 112345
#define left(p) (p) << 1
#define right(p) ((p) << 1) + 1

typedef struct {int min, max;} inter_t;

int n, a[MAX];
inter_t st[4*MAX];

void build(int p, int l, int r){
  int p1, p2;

  if(l == r){st[p].min = st[p].max = l; return;}
  build(left(p), l, (l+r)/2);
  build(right(p), (l+r)/2 + 1, r);
  p1 = st[left(p)].min; p2 = st[right(p)].min;
  st[p].min = a[p1] <= a[p2] ? p1 : p2;
  p1 = st[left(p)].max; p2 = st[right(p)].max;
  st[p].max = a[p1] >= a[p2] ? p1 : p2;
}

int rmq(int p, int l, int r, int i, int j, int op){
  int p1, p2;

  if(i > r || j < l) return -1;
  if(l >= i && r <= j)
    return op == 0 ? st[p].min : st[p].max;
  p1 = rmq(left(p), l, (l+r)/2, i, j, op);
  p2 = rmq(right(p), (l+r)/2 + 1, r, i, j, op);
  if(p1 == -1) return p2;
  if(p2 == -1) return p1;
  if(op == 0) return (a[p1] <= a[p2]) ? p1 : p2;
  return (a[p1] >= a[p2]) ? p1 : p2;
}

void update(int p, int l, int r, int i){
  int p1, p2;
  if(i > r || i < l) return;
  if(l == r) return;
  update(left(p), l, (l+r)/2, i);
  update(right(p), (l+r)/2 + 1, r, i);
  p1 = st[left(p)].min; p2 = st[right(p)].min;
  st[p].min = a[p1] <= a[p2] ? p1 : p2;
  p1 = st[left(p)].max; p2 = st[right(p)].max;
  st[p].max = a[p1] >= a[p2] ? p1 : p2;
}

int main(void){
  int i, q, j, op, ans;

  while(scanf("%d", &n) != EOF){
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    //for(i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
    build(1, 0, n-1);
    //printf("%d %d\n", a[rmq(1, 0, n-1, 2, 3, 0)], a[rmq(1, 0, n-1, 2, 3, 1)]);
    scanf("%d", &q);
    while(q--){
      scanf("%d %d %d", &op, &i, &j);
      if(op == 1){
        a[i-1] = j;
        update(1, 0, n-1, i-1);
        //for(i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
      }
      else{
        ans = abs(a[rmq(1, 0, n-1, i-1, j-1, 0)] - a[rmq(1, 0, n-1, i-1, j-1, 1)]);
        printf("%d\n", ans);
      }
    }
  }

  return 0;
}
