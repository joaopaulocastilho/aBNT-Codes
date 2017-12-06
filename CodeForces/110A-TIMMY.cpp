#include <cstdio>

int main(void){
  char c;
  int count = 0;
  while((c = getchar()) != EOF)
    if(c == '4' || c == '7'){
      if(count == 7){
	printf("NO\n");
	return 0;
      }
      count++;
    }
  if(count == 4 || count == 7) printf("YES\n");
  else printf("NO\n");
  return 0;
}
    
