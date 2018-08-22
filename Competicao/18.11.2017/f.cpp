#include <cstdio>

#define MAX 112345
#define INF 1123456789

int main(void){
  int n, arr[MAX], anterior, proximo, menor;
  int troquei = 0, aux, idx, j;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  for(int i = 0; i < n; i++){
    if(i == 0) anterior = -1;
    else anterior = arr[i - 1];
    //if(i == n-1) proximo = INF;
    //else proximo = arr[i+1];
    if(arr[i] >= anterior) continue;
    if(troquei){
      //for(int k = 0; k < n; k++) printf("%d", arr[k]);
      printf("NO\n");
      return 0;
    }
    menor = arr[i];
    idx = i;
    for(j = i+1; j < n; j++){
      if(arr[j] > menor) continue;
      menor = arr[j];
      idx = j;
    }
    for(j = 0; j < n && arr[idx] >= arr[j]; j++);
    aux = arr[j];
    arr[j] = arr[idx];
    arr[idx] = aux;
    troquei = 1;
    i = 0;
  }
  //  for(int i = 0; i < n; i++) printf("%d", arr[i]);
  printf("YES\n");
  return 0;
}
