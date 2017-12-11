#include <stdio.h>
#include <string.h>

#define MAX 112345
#define left(x) 2 * (x)
#define right(x) 2 * (x) + 1

typedef struct{int great, ind;} node_t;

int mesadas[MAX], lazy[4*MAX];;
node_t st[4*MAX], null;

void build(int node, int l, int r);
void update(int node, int l, int r, int i, int j, int val);
node_t query(int node, int l, int r, int i, int j);

int main(void){
  int n, q, i, j, k;
  char op;
  node_t ans;

  null.ind = -1;
  while(scanf("%d %d", &n, &q) != EOF){
    memset(lazy, 0, sizeof(lazy));
    for(int i = 0; i < n; i++) scanf("%d", &mesadas[i]);
    build(1, 0, n-1);
    //for(int i = 1; i <= 9; i++) printf("(G:%d,I:%d) ", st[i].great, st[i].ind); printf("\n");
    while(q--){
      scanf(" %c", &op);
      if(op == 'C'){
        scanf("%d %d", &i, &j); i--; j--;
        ans = query(1, 0, n-1, i, j);
        printf("%d\n", ans.ind + 1);
      }
      else{
        scanf("%d %d %d", &i, &j, &k); i--; j--;
        update(1, 0, n-1, i, j, k);
      }
    }
  }
  return 0;
}

//ARRUMADA
void build(int node, int l, int r){
  node_t p1, p2;
  if(l == r){ st[node].great = mesadas[l]; st[node].ind = l; return; }
  build(left(node), l, (l+r)/2);
  build(right(node), (l+r)/2 + 1, r);
  p1 = st[left(node)]; p2 = st[right(node)];
  st[node].great = p1.great >= p2.great ? p1.great : p2.great;
  st[node].ind = p1.great >= p2.great ? p1.ind : p2.ind;
}

void update(int node, int l, int r, int i, int j, int val){
  int mid = (l+r)/2;
  node_t p1, p2;
  if(lazy[node]){
    st[node].great += lazy[node];
    if(l != r){
      lazy[right(node)] += lazy[node];
      lazy[left(node)] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(l > r || l > j || i > r) return;
  if(i <= l && r <= j){
    st[node].great += val;
    if(l != r){
      lazy[right(node)] += val;
      lazy[left(node)] += val;
    }
  }
  else{
    update(left(node), l, mid, i, j, val);
    update(right(node), mid+1, r, i, j, val);
    p1 = st[left(node)]; p2 = st[right(node)];
    st[node].great = p1.great >= p2.great ? p1.great : p2.great;
    st[node].ind = p1.great >= p2.great ? p1.ind : p2.ind;
  }
}

node_t query(int node, int l, int r, int i, int j){
  int mid = (l+r)/2;
  if(lazy[node]){
    st[node].great += lazy[node];
    if(l != r){
      lazy[left(node)] += lazy[node];
      lazy[right(node)] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(l > r || l > j || i > r) return null;
  if(i <= l && r <= j) return st[node];
  else{
    node_t p1 = query(left(node), l, mid, i, j);
    node_t p2 = query(right(node), mid+1, r, i, j);
    if(p1.ind == -1) return p2;
    if(p2.ind == -1) return p1;
    return p1.great >= p2.great ? p1 : p2;
  }
}
