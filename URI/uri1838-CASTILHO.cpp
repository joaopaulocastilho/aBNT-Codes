#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 1123
#define MAXPD 4123

int Ti[MAX], Tf[MAX], in[MAX], N;
int S[MAXPD][MAXPD];

int cmp(const void *a, const void *b){
  if(Ti[*(int*)a] == Ti[*(int*)b])
    return Tf[*(int*)a] - Tf[*(int*)b];
  return Ti[*(int*)a] - Ti[*(int*)b];
}

int PD(int i, int k){
  if(S[i][k] != -1) return S[i][k];
  if(i==N) return S[i][k] = 0;
  if(k>Ti[in[i]]) return S[i][k] = PD(i+1, k);
  return S[i][k] = max(Tf[in[i]]-Ti[in[i]]+PD(i+1, Tf[in[i]]), PD(i+1, k));
}

int main(void){
  int i;
  scanf("%d", &N);
  memset(S, -1, sizeof(S));
  for(i=0; i<N; i++){ scanf("%d %d", &Ti[i], &Tf[i]); in[i] = i; }
  qsort(in, N, sizeof(int), &cmp);
  printf("%d\n", PD(0, 1));
  return 0;
}
