#include <cstdio>
#include <cstring>

#define MAX 11234
#define left(p) (p) << 1
#define right(p) ((p) << 1) + 1


int a[MAX], n, st[4*MAX];

void build(int p, int l, int r){
  int p1, p2;

  if(l == r){ st[p] = l; return; }
  build(left(p), l, (l+r)/2);
  build(right(p), (l+r)/2 + 1, r);
  p1 = st[left(p)]; p2 = st[right(p)];
  st[p] = a[p1] <= a[p2] ? p1 : p2;
}

int rmq(int p, int l, int r, int i, int j){
  int p1, p2;
  
  if(i > r || j < l) return -1; //Esse segmento não está no intervalo necessario
  if(l >= i && r <= j) return st[p]; //Esse segmento esta inteiro na query
  p1 = rmq(left(p), l, (l+r)/2, i, j);
  p2 = rmq(right(p), (l+r)/2 + 1, r, i, j);
  if(p1 == -1) return p2;
  if(p2 == -1) return p1;
  return (a[p1] <= a[p2]) ? p1 : p2;  
}

void update(int p, int l, int r, int i){
  if(i > r || i < l) return; //Fora do escopo.
  if(l >= i && r <= i){ //Eh a folha que eu quero.
    for(i = p >> 1; i >= 1; i = i >> 1){ // Sobe ate a raiz atualizando rmq.
      int p1 = st[left(i)], p2 = st[right(i)];
      st[i] = a[p1] <= a[p2] ? p1 : p2;
    }
    return;
  }
  update(left(p), l, (l+r)/2, i);
  update(right(p), (l+r)/2 + 1, r, i);
}


int main(void){
  int i, j, b ,c;
  scanf("%d", &n);
  memset(st, -1, sizeof(st));
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  build(1, 0, n-1);
  for(i = 1; st[i] != -1; i++) printf("%d ", st[i]); // printa
  scanf("%d %d", &i, &j);
  printf("\n%d\n", rmq(1, 0, n-1, i, j));
  scanf("%d %d", &b, &c); // leia indice e valor pra trocar
  a[b] = c;
  update(1, 0, n-1, b); //atualize
  for(i = 1; st[i] != -1; i++) printf("%d ", st[i]); // printa
  printf("\n");
  for(i = 0; i < n; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
