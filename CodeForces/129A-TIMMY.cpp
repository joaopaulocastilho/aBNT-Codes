#include <cstdio>

#define MAX 1123

int main(void){
  int n, arr[MAX], sum = 0, count = 0;
  
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
    sum += arr[i];
  }
  for(int i = 0; i < n; i++)
    if((sum - arr[i]) % 2 == 0) count++;
  printf("%d\n", count);
  return 0;
}
