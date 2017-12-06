#include <cstdio>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define MAX 1123

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int main(void){
  int n, arr[MAX], flag = 1, count = 0, troquei = 1;;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  for(int i = 0; i < n; i++){
    if((arr[i] % 2) != 0) flag = 0;
  }
  if(flag){
    printf("-1\n");
    return 0;
  }
  while(troquei){
    for(int i = 0; i < n-1; i++){
      troquei = 0;
      if((arr[i] % 2) == 0 && (arr[i+1] % 2) != 0 && (max(arr[i], arr[i+1]) % min(arr[i], arr[i+1])) != 0){
	troquei = 1;
	arr[i] = gcd(arr[i], arr[i+1]);
	count++;
      }
      else if((arr[i] % 2) != 0 && (arr[i+1] % 2) == 0 && (max(arr[i], arr[i+1]) % min(arr[i], arr[i+1])) != 0){
	troquei = 1;
	arr[i+1] = gcd(arr[i], arr[i+1]);
	count++;
      }
    }
  }
  for(int i = 0; i < n; i++){
    if(arr[i] != 1){
      printf("-1\n");
      return 0;
    }
  }
  printf("%d\n", count);
  return 0;
}
