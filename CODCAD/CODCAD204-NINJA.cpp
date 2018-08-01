#include <stdio.h>
#include <string.h>

#define MAX 112345
#define left(x) 2 * (x)
#define right(x) 2 * (x) + 1

int caixas[MAX], st[4*MAX], lazy[4*MAX];

void build(int node, int l, int r);
int query(int node, int l, int r, int i, int j);
void update(int node, int l, int r, int i, int j, int val);

int main(void){
  int n, q, op, i, j, k;

  memset(lazy, 0, sizeof(lazy));
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; i++) scanf("%d", &caixas[i]);
  build(1, 0, n-1);
  //for(int i = 1; i < 10; i++) printf("%d ", st[i]); printf("\n");
  while(q--){
    scanf("%d", &op);
    if(op == 1){
      scanf("%d %d %d", &i, &j, &k); i--; j--;
      update(1, 0, n-1, i, j, k);
    }
    else{
      scanf("%d %d", &i, &j); i--; j--;
      printf("%d\n", query(1, 0, n-1, i, j));
    }
  }

  return 0;
}

void build(int node, int l, int r){
  int p1, p2;
  if(l == r) { st[node] = caixas[l]; return; }
  build(left(node), l, (l+r)/2);
  build(right(node), (l+r)/2 + 1, r);
  p1 = st[left(node)]; p2 = st[right(node)];
  st[node] = p1 + p2;
}

int query(int node, int l, int r, int i, int j){
  int mid = (l+r)/2;
  if(lazy[node]){ //Existem operações a serem feitas
    st[node] = lazy[node] * (r-l+1); //A mesma soma de antes
    if(l != r){ //Se o nó tem filhos, seta o lazy deles
      lazy[left(node)] = lazy[node];
      lazy[right(node)] = lazy[node];
    }
    lazy[node] = 0;
  }
  if(l > r || l > j || i > r) return 0; //[l,r] e [i,j] sao disjuntos
  if(i <= l && r <= j) return st[node]; //[l, r] esta contido em [i,j]
  else{ //Retorna a soma dos descendentes
    int leftsum = query(left(node), l, mid, i, j);
    int rightsum = query(right(node), mid+1, r, i, j);
    return leftsum + rightsum;
  }
}

void update(int node, int l, int r, int i, int j, int val){
  int mid = (l+r)/2;
  if(lazy[node]){ //Se existirem operações atrasadas, temos que faze-las
    st[node] = lazy[node] * (r-l+1); // Se for (3,5) = 5-3+1 = 3 -> (3,4,5)
    if(l != r){ //Se o nó possui filhos, propago o lazy para eles
      lazy[right(node)] = lazy[node];
      lazy[left(node)] = lazy[node];
    }
    lazy[node] = 0; //Como ja atualizamos e propagamos, zeramos o lazy do no
  }
  if(l > r || l > j || i > r) return; //atualizacao nao afeta o no
  if(i <= l && r <= j){ //Se a operação cobre o nó todo
    st[node] = val * (r-l+1); //Atualiza a operação
    if(l != r){ //Se possui filhos, seta o lazy deles
      lazy[right(node)] = val;
      lazy[left(node)] = val;
    }
  }
  else{ //Caso a função atualize apenas alguns valores do no, chamamos nos filhos
    update(left(node), l, mid, i, j, val);
    update(right(node), mid+1, r, i, j, val);
    st[node] = st[left(node)] + st[right(node)];
  }
}
