#include <cstdio>
#include <cstdlib>

using namespace std;

int compare(const void * a, const void * b){ return ( * (int*)a - *(int*)b); } 

int main(void){
  int maof[3], maom[2], maior[3], aux[3], num;
  while(scanf("%d %d %d %d %d", &maof[0], &maof[1], &maof[2], &maom[0], &maom[1]), maof[1] != 0){
    maior[0] = maior[1] = maior[2] = 0;
    qsort(maof, 3, sizeof(int), compare);
    qsort(maom, 2, sizeof(int), compare);
    for(num = 1; num <= 52; num++){
      if(num == maof[0] ||num == maof[1] || num == maof[2] || num == maom[0] || num == maom[1]) continue;
      aux[0] = maom[0]; aux[1] = maom[1]; aux[2] = num;
      qsort(aux, 3, sizeof(int), compare);
      maior[0] = maior[1] = maior[2] = 0;
      for(int i = 2; i >= 0; i--)
	for(int j = 2; j >= 0; j--){
	  if(maof[i] > aux[j] && maior[j] != 1){
	    maior[j]++;
	    break;
	  }
	}
      if((maior[0] && maior[1]) || (maior[0] && maior[2]) || (maior[1] && maior[2])) continue;
      printf("%d\n", num);
      break;
    }
    if(num >= 53) printf("-1\n");
  }
  return 0;
}
