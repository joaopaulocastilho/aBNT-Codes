#include <cstdio>
#include <cstring>

#define MAX 112

int main(void){
  char str[MAX];
  int len, cmin = 0, cmai = 0;
  
  scanf("%s", str);
  len = strlen(str);
  for(int i = 0; i < len; i++)
    if(str[i] >= 'a' && str[i] <= 'z') cmin++;
    else cmai++;
  for(int i = 0; i < len; i++)
    if(str[i] >= 'a' && str[i] <= 'z'){
      if(cmin < cmai)
	str[i] += 'A' - 'a';
    }
    else
      if(cmin >= cmai)
	str[i] -= 'A' - 'a';
  printf("%s\n", str);
  return 0;
}
  
