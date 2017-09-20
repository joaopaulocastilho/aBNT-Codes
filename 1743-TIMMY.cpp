#include <stdio.h>


int main(void){
  int i, v1[5], v2[5];

  for(i = 0; i < 5; i++) scanf("%d", &v1[i]);
  for(i = 0; i < 5; i++) scanf("%d", &v2[i]);
  for(i = 0; i < 5; i++){
    if(!(v1[i] ^ v2[i])){
      printf("N\n");
      return 0;
    }
  }
  printf("Y\n");
  return 0; 
}
