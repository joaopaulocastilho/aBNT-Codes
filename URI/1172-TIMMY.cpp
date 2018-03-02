#include <cstdio>


int main(void){
  int vector[10];
  for(int i = 0; i < 10; i++){
    scanf("%d", &vector[i]);
    if(vector[i] <= 0) vector[i] = 1;
    printf("X[%d] = %d\n", i, vector[i]);
  }
  return 0;
}
