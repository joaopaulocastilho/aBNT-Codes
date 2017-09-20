#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 212345

int N, C, p[MAX];
int S[2][MAX];

int PD(int c, int i){
  if(S[c][i] != -1) return S[c][i];
  if(i==N) return S[c][i] = 0;
  if(c==0) return S[c][i] = max(PD(1, i+1)-C-p[i], PD(0, i+1));
  return S[c][i] = max(p[i]+PD(0, i+1), PD(1, i+1));
}

int main(void){
  int i;
  scanf("%d %d", &N, &C);
  memset(S, -1, sizeof(S));
  for(i=0; i<N; i++) scanf("%d", &p[i]);
  printf("%d\n", PD(0, 0));
  return 0;
}
