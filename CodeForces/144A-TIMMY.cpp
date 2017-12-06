#include <cstdio>

#define MAX 112
#define INF 101

int main(void){
  int n, menor = INF, maior = -1, arr[MAX], idxma, idxm, count = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  for(int i = 0; i < n; i++){
    if(arr[i] <= menor){
      menor = arr[i];
      idxm = i;
    }
    if(arr[i] > maior){
      maior = arr[i];
      idxma = i;
    }
  }
  if(idxma > idxm){
    idxma--;
  }
  //  printf("%d %d\n", idxma, idxm);
  count = idxma + ((n-1)-idxm);
  printf("%d\n", count);
  return 0;
}
