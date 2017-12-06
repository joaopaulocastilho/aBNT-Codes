#include <cstdio>

#define MAX 112

int main(void){
  char c;
  int arr1[MAX], arr2[MAX];
  for(int i = 0; (c = getchar()) != '\n'; i++)
    arr1[i] = c - '0';
  for(int i = 0; (c = getchar()) != '\n'; i++){
    arr2[i] = c - '0';
    printf("%d", arr1[i] ^ arr2[i]);
  }
  printf("\n");
  return 0;
}
