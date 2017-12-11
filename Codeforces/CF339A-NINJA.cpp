#include <stdio.h>
#include <stdlib.h>

#define MAX 112

int cmp(const void *a, const void *b){
  return *(int *)a - *(int *)b;
}

int main(void){  
  int x, nums[MAX], i = 0, j;
  char c;
  
  while(scanf("%d", &nums[i++]) != EOF) scanf("%c", &c); 
  i--;
  qsort(nums, i, sizeof(int), &cmp);
  for(j = 0; j < i; j++){
    if(j) printf("+");
    printf("%d", nums[j]);
  }
  printf("\n");
	
  return 0;
}
