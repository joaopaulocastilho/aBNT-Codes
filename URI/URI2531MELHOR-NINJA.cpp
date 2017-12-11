#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

#define MAX 112345
#define left(p) (p) << 1
#define right(p) ((p) << 1) + 1

typedef struct {int min, max;} inter_t;

int n, a[MAX], gmin, gmax;
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

void updateMinMax(int nmin, int nmax){
  if(gmin == -1){ gmin = nmin; gmax = nmax; }
  else{
    gmin = a[gmin] <= a[nmin] ? gmin : nmin;
    gmax = a[gmax] >= a[nmax] ? gmax : nmax;
  }
}

void rmq(int p, int l, int r, int i, int j){
  if(i > r || j < l) return;
  if(l >= i && r <= j){ updateMinMax(st[p].min, st[p].max); return;}
  rmq(left(p), l, (l+r)/2, i, j);
  rmq(right(p), (l+r)/2 + 1, r, i, j);
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
    //gmin = gmax = -1;
    //rmq(1, 0, n-1, i-1, j-1);
    //printf("%d %d\n", gmin, gmax);
    scanf("%d", &q);
    while(q--){
      scanf("%d %d %d", &op, &i, &j);
      if(op == 1){
        a[i-1] = j;
        update(1, 0, n-1, i-1);
        //for(i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
      }
      else{
        gmin = gmax = -1;
        rmq(1, 0, n-1, i-1, j-1);
        printf("%d\n", abs(a[gmin] - a[gmax]));
      }
    }
  }

  return 0;
}
