#include <stdio.h>

int main(void){
  int i, n, alt[5], cho;
  char ans[] = "ABCDE";
  
  while(scanf("%d", &n), n){
    while(n--){
      cho = -1;
      for(i = 0; i < 5; i++) scanf("%d", &alt[i]);
      for(i = 0; i < 5; i++){
	if(alt[i] <= 127){
	  if(cho != -1){ cho = -1; break; }
	  cho = i;
	}
      }
      printf("%c\n", cho == -1 ? '*' : ans[cho]);
    }
  }
  
  return 0;
}
