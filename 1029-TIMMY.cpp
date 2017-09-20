#include <stdio.h>
#include <string.h>


int calls = 2, matrix[36][2];

int fibonacci(int a, int calls){
  if(matrix[a][1] != -1) return a;
  if(a == 0){
    matrix[a][1] = 0;
    matrix[a][2] = 0;
    return a;
  }
  if(a == 1){
    matrix[a][1] = 1;
    matrix[a][2] = 0;
    return a;
  }
  calls +=2;
  matrix[a][1] = fibonacci(a-1, calls) + fibonacci(a-2, calls);
  matrix[a][2] = calls;
  return a;
}

int main(void){
  int n, a, ans;
  memset(matrix, -1, sizeof(matrix));
  scanf("%d", &n);
  while(n--){
    scanf("%d", &a);
    ans = fibonacci(a, calls);
    
    printf("fib(%d) = %d calls = %d\n", a, matrix[ans][2], matrix[ans][1]);
  }
  return 0;
}
