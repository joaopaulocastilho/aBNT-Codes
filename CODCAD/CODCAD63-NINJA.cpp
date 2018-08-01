#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 112345

int id[MAX], sz[MAX]; //Vetor dos representantes de classe e tamannhos de árvores

void Make(int p){ id[p] = p; sz[p] = 1; } //Representante de um conjunto unitário é ele mesmo, tamanho é 1
int Find(int p){ return (id[p] == p) ? p : (id[p] = Find(id[p])); } //Vai até o representante e o retorna, comprimindo o caminho
void Union(int p, int q){
  p = Find(p); q = Find(q); //Pega os representantes das classes
  if(p == q) return; //Se forem iguais, já estão unidos, nada a fazer
  if(sz[p] > sz[q]) swap(p, q); //Garante que p sempre possua o representante da menor árvore
  id[p] = q; //Une p a q
  sz[q] += sz[p]; //Atualiza a profundidade da árvore q
}

int main(void){
  int n, k, i, u, v;
  char op;
  
  scanf("%d %d ", &n, &k);
  for(i = 1; i <= n; i++) Make(i);
  while(k--){
    scanf("%c %d %d ", &op, &u, &v);
    if(op == 'C') printf("%c\n", Find(u) == Find(v) ? 'S' : 'N');
    else Union(u, v);
  }

  return 0;
}
