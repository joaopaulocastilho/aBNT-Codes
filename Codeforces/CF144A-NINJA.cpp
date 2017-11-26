#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 112

int main(void){
  int sold[MAX], n, i, j, max = -1, min = MAX, ans = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &sold[i]);
    if(sold[i] > max) max = sold[i];
    if(sold[i] < min) min = sold[i];
  }
  //printf("%d %d\n", min, max);
  for(i = 0; i < n; i++){
    if(sold[i] == max){
      for(j = i; j; j--, ans++){
	swap(sold[j], sold[j-1]);
	//printf("Trocando %d e %d\n", sold[j], sold[j-1]);
      }
      break;
    }
  }
  for(i = n-1; i >= 0; i--){
    if(sold[i] == min){
      for(j = i; j < n-1; j++, ans++){
	swap(sold[j], sold[j+1]);
	//printf("Trocando %d e %d\n", sold[j], sold[j+1]);	
      }
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
