#include <stdio.h>
#include <string.h>
#include <utility>

#define left(x) 2 * (x)
#define right(x) 2 * (x) + 1

using namespace std;

#define MAX 1123456

typedef pair<int,int> ii;

int pirates[MAX], lazy[4*MAX];
ii st[4*MAX];

void build(int node, int l, int r);
void update(int node, int l, int r, int i, int j, int op);
int query(int node, int l, int r, int i, int j);

int main(void){
  int z, m, t, n, i, j, q, question, caso = 1;
  char tmp[60], op;

  scanf("%d", &z);
  while(z--){
    memset(lazy, 0, sizeof(lazy));
    question = 1;
    n = 0;
    scanf("%d", &m);
    while(m--){
      scanf("%d", &t);
      scanf(" %s", tmp);
      while(t--)
        for(int i = 0; tmp[i] != '\0'; i++)
          pirates[n++] = tmp[i] - '0';
    }
    build(1, 0, n-1);
    printf("Case %d:\n", caso++);
    scanf("%d", &q);
    while(q--){
      scanf(" %c %d %d", &op, &i, &j);
      switch(op){
        case 'F': update(1, 0, n-1, i, j, 1); break;
        case 'E': update(1, 0, n-1, i, j, 2); break;
        case 'I': update(1, 0, n-1, i, j, 3); break;
        case 'S': printf("Q%d: %d\n", question++, query(1, 0, n-1, i, j));
      }
    }
  }
  return 0;
}

void build(int node, int l, int r){
  ii p1, p2;
  if(l == r) {
    st[node].first = pirates[l] == 0 ? 1 : 0;
    st[node].second = pirates[l] == 1 ? 1 : 0;
    return;
  }
  build(left(node), l, (l+r)/2);
  build(right(node), (l+r)/2 + 1, r);
  p1 = st[left(node)]; p2 = st[right(node)];
  st[node].first = p1.first + p2.first;
  st[node].second = p1.second + p2.second;
}

void update(int node, int l, int r, int i, int j, int op){
  int tmp, respl, respr;
  int mid = (l+r)/2;
  if(lazy[node]){
    switch(lazy[node]){
      case 1: st[node].second += st[node].first; st[node].first = 0; break;
      case 2: st[node].first += st[node].second; st[node].second = 0; break;
      case 3:
        tmp = st[node].first;
        st[node].first = st[node].second;
        st[node].second = tmp;
        break;
    }
    if(l != r){
      respl = respr = lazy[node];
      if(lazy[node] == 3){
        if(lazy[left(node)] == 1) respl = 2;
        if(lazy[right(node)] == 1) respr = 2;
        if(lazy[left(node)] == 2) respl = 1;
        if(lazy[right(node)] == 2) respr = 1;
        if(lazy[left(node)] == 3) respl = 0;
        if(lazy[right(node)] == 3) respr = 0;
      }
      lazy[left(node)] = respl;
      lazy[right(node)] = respr;
    }
    lazy[node] = 0;
  }
  if(l > r || l > j || i > r) return;
  if(i <= l && r <= j){
    switch(op){
      case 1: st[node].second += st[node].first; st[node].first = 0; break;
      case 2: st[node].first += st[node].second; st[node].second = 0; break;
      case 3:
        tmp = st[node].first;
        st[node].first = st[node].second;
        st[node].second = tmp;
        break;
    }
    if(l != r){
      respl = respr = op;
      if(op == 3){
        if(lazy[left(node)] == 1) respl = 2;
        if(lazy[right(node)] == 1) respr = 2;
        if(lazy[left(node)] == 2) respl = 1;
        if(lazy[right(node)] == 2) respr = 1;
        if(lazy[left(node)] == 3) respl = 0;
        if(lazy[right(node)] == 3) respr = 0;
      }
      lazy[left(node)] = respl;
      lazy[right(node)] = respr;
    }
  }
  else{
    update(left(node), l, mid, i, j, op);
    update(right(node), mid+1, r, i, j, op);
    st[node].first = st[left(node)].first + st[right(node)].first;
    st[node].second = st[left(node)].second + st[right(node)].second;
  }
}

int query(int node, int l, int r, int i, int j){
  int mid = (l+r)/2, respl, respr, tmp;
  if(l > r || l > j || i > r) return 0;
  if(lazy[node]){
    switch(lazy[node]){
      case 1: st[node].second += st[node].first; st[node].first = 0; break;
      case 2: st[node].first += st[node].second; st[node].second = 0; break;
      case 3:
        tmp = st[node].first;
        st[node].first = st[node].second;
        st[node].second = tmp;
        break;
    }
    if(l != r){
      respl = respr = lazy[node];
      if(lazy[node] == 3){
        if(lazy[left(node)] == 1) respl = 2;
        if(lazy[right(node)] == 1) respr = 2;
        if(lazy[left(node)] == 2) respl = 1;
        if(lazy[right(node)] == 2) respr = 1;
        if(lazy[left(node)] == 3) respl = 0;
        if(lazy[right(node)] == 3) respr = 0;
      }
      lazy[left(node)] = respl;
      lazy[right(node)] = respr;
    }
    lazy[node] = 0;
  }
  if(i <= l && r <= j) return st[node].second;
  else{
    int leftsum = query(left(node), l, mid, i, j);
    int rightsum = query(right(node), mid+1, r, i, j);
    return leftsum + rightsum;
  }
}
