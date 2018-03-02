#include <cstdio>

#define MAX 112345

int main(void){
  int posme = 1, posf = 1000000, tc, gift[MAX], middle = posf/2, ans;
  scanf("%d", &tc);
  for(int i = 0; i < tc; i++){
    scanf("%d", &gift[i]);
  }
  for(int i = 0; i < tc && gift[i] <= middle; i++)
    posme = gift[i];
  for(int j = tc-1; j >= 0 && gift[j] > middle; j--)
    posf = gift[j];
  if(posme - 1 > 1000000 - posf) ans = posme - 1;
  else ans = 1000000 - posf;    
  printf("%d\n", ans);
  return 0;
}
