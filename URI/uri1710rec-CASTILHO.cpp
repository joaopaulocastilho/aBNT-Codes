#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define MAXP 1123
#define MAX 11234

typedef struct{ int a, b, c, d; }plano_t;
typedef struct{ int x, y, z; }planeta_t;

char bm[MAX][MAX];

int cmp(const void *a, const void *b){
    return strcmp((char*) a, (char*) b);
}

int maior(int tam, int i){
  int cont=1;
  if(i == tam) return 0;
  while(!strcmp(bm[i], bm[i+1])){ cont++; i++; }
  return max(cont, maior(tam, i+1));
}

int main(void){
  int m, n, i, j;
  plano_t p[MAXP];
  planeta_t a;
  scanf("%d%d", &m, &n);
  memset(bm, 0, sizeof(bm));
  for(i=0; i<m; i++) scanf("%d%d%d%d", &(p[i].a), &(p[i].b), &(p[i].c), &(p[i].d));
  for(i=0; i<n; i++){
    scanf("%d%d%d", &a.x, &a.y, &a.z);
    for(j=0; j<m; j++){
      if(a.x*p[j].a + a.y*p[j].b + a.z*p[j].c < p[j].d) bm[i][j] = '0';
      else bm[i][j] = '1';
    }
  }
  
  qsort(bm, n, sizeof(bm[0]), &cmp);
  // for(i=0; i<n; i++) printf("%s\n", bm[i]);
  printf("%d\n", maior(n, 0));
  return 0;
}
