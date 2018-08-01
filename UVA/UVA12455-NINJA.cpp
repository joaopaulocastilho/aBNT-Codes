#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void){
  int i, j, t, sz, n, sizes[MAX], tmp[MAX], bars[MAX]; 

  scanf("%d", &t);
  while(t--){
    memset(sizes, 0, sizeof(sizes));
    memset(tmp, 0, sizeof(tmp));
    sizes[0] = 1;
    scanf("%d", &sz);
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &bars[i]);
    for(i = 0; i < n; i++){
      for(j = 0; j <= sz; j++)
	if(j+bars[i] <= sz && sizes[j]) tmp[j+bars[i]] = 1;
      for(j = 0; j <= sz; j++){
	sizes[j] |= tmp[j];
	tmp[j] = 0;
      }	
    }
    printf("%s\n", sizes[sz] ? "YES" : "NO");
  }

  return 0;
}
