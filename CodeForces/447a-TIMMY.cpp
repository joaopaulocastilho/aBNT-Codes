#include <cstdio>
#include <cstring>

#define MAX 112

int count = 0;
char str[MAX];
int len;

int main(void){
  scanf("%s", str);
  len = strlen(str);
  for(int i = 0; i < len; i++)
    if(str[i] == 'Q')
      for(int j = i; j < len; j++)
	if(str[j] == 'A')
	  for(int k = j; k < len; k++)
	    if(str[k] == 'Q')
	      count++;
  printf("%d\n", count);
  return 0;
}
