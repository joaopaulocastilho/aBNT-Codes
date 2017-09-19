#include <stdio.h>
#include <stdlib.h>

#define MAX 3123
#define INF 512345678

int x[MAX], y[MAX], in[MAX];

int cmp(const void *a, const void *b){
  return x[*(int*)a] - x[*(int*)b];
}

int main(void){
  int N, i, j, cont=0, dist_b, dist_c, odist;
  scanf("%d", &N);
  for(i=0; i<N; i++){
    scanf("%d%d", &x[i], &y[i]);
    in[i] = i;
  }
  qsort(in, N, sizeof(int), &cmp);
  for(i=0; i<N-1; i++){
    dist_b=dist_c=INF;
    for(j=i+1; j<N; j++){
      odist = abs(y[in[i]]-y[in[j]]);
      if(y[in[i]] < y[in[j]]){
	if(odist<dist_c){
	   dist_c = odist;
	   cont++;
	}
      }else{
	if(odist<dist_b){
	   dist_b = odist;
	   cont++;
	}}}}
  printf("%d\n", cont);
  return 0;
}
