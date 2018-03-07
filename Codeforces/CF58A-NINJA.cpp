#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, j, k, l, m, end, ans = 0;
  char str[MAX];

  scanf("%s", str);
  end = strlen(str);
  for(i = 0; i < end; i++)
    if(str[i] == 'h')
      for(j = i+1; j < end; j++)
	if(str[j] == 'e')
	  for(k = j+1; k < end; k++)
	    if(str[k] == 'l')
	      for(l = k+1; l < end; l++)
		if(str[l] == 'l')
		  for(m = l+1; m < end; m++)
		    if(str[m] == 'o') ans = 1;
  printf("%s\n", ans ? "YES" : "NO");

  return 0;
}
