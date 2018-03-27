#include <stdio.h>

#define MAX 21

int main(void){
  int i, j, k, l, m, o, n, first = 1, v[MAX];

  while(scanf("%d", &n), n){
    for(i = 0; i < n; i++) scanf("%d", &v[i]);

    if(first) first = 0;
    else printf("\n");
    for(i = 0; i < n-5; i++)
      for(j = i+1; j < n-4; j++)
	for(k = j+1; k < n-3; k++)
	  for(l = k+1; l < n-2; l++)
	    for(m = l+1; m < n-1; m++)
	      for(o = m+1; o < n; o++)
		printf("%d %d %d %d %d %d\n", v[i], v[j], v[k], v[l], v[m], v[o]); 
  }

  return 0;
}
