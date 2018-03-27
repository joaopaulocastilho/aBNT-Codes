#include <cstdio>
#include <cmath>
#include <cstring>

#define MAX 1123

int main(void){
  int pages, npages, front;
  int v[MAX];
  while(scanf("%d", &pages), pages != 0){
    memset(v, 0, sizeof(v));
    front = 1;
    npages = (int)(ceil(((double)pages)/4) * 4);
    //printf("%d\n", npages);
    printf("Printing order for %d pages:\n", pages);
    for(int i = 1, j = pages, k = 0; i <= j;k++){
      if(front && k % 2 != 0){
	v[k] = i++;
	front = 0;
      }
      else if(front && k % 2 == 0){
	if(j < npages - k/2 ) v[k] = -1;
	else v[k] = j--;
      }
      else if(!front && k % 2 != 0){
	if(j < npages - k/2) v[k] = -1;
	else v[k] = j--;
	front = 1;
      }
      else{
	v[k] = i++;
      }
    }
    for(int i = 0, state = 0; i < npages; i+=2, state++){
      if(v[i] == 0 && v[i+1] == 0) continue;
      printf("Sheet %d, %s: ", (int)floor(1 + ((double)i)/4), state % 2 != 0 ? "back " : "front");
      if(v[i] == -1 || v[i] == 0) printf("Blank, "); else printf("%d, ", v[i]);
      if(v[i+1] == -1 || v[i+1] == 0) printf("Blank\n"); else printf("%d\n", v[i+1]);
    }
  }
  return 0;
}
