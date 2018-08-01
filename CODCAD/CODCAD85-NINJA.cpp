#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 112345

int id[MAX], sz[MAX], points[MAX]; //Vetor dos representantes de classe e tamannhos de árvores

void Make(int p){ id[p] = p; sz[p] = 1; } //Representante de um conjunto unitário é ele mesmo, tamanho é 1
int Find(int p){ return (id[p] == p) ? p : (id[p] = Find(id[p])); } //Vai até o representante e o retorna, comprimindo o caminho
void Union(int p, int q){
  p = Find(p); q = Find(q); //Pega os representantes das classes
  if(p == q) return; //Se forem iguais, já estão unidos, nada a fazer
  if(sz[p] > sz[q]) swap(p, q); //Garante que p sempre possua o representante da menor árvore
  id[p] = q; //Une p a q
  sz[q] += sz[p]; //Atualiza a profundidade da árvore q
  points[q] += points[p];
}

int main(void){
  int n, m, i, op, u, v, ans;

  while(scanf("%d %d", &n, &m), n){
    for(i = 1, ans = 0; i <= n; i++) {
      Make(i);
      scanf("%d", &points[i]);
    }
    while(m--){
      scanf("%d %d %d", &op, &u, &v);
      if(op == 1) Union(u, v);
      else if( (Find(1) == Find(u) && points[Find(u)] > points[Find(v)]) ||
	       (Find(1) == Find(v) && points[Find(v)] > points[Find(u)]) )
	ans ++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
