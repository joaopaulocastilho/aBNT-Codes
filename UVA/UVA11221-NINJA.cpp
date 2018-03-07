#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 11234
#define MAX2 112
#define EPS 1.0E-3

int main(void){
  double squarer; 
  int i, j, k, t, end, ans, dim, caso = 1;
  char line[MAX], str[MAX], square[MAX2][MAX2];

  scanf("%d ", &t);
  while(t--){
    ans = 1;
    fgets(line, MAX, stdin);
    end = strlen(line);
    for(j = i = 0; i < end; i++)
      if(line[i] >= 'a' && line[i] <= 'z') str[j++] = line[i];
    str[j] = 0;
    squarer = sqrt(strlen(str));
    //printf("%lf\n", squarer);
    if(squarer - (int)squarer > EPS) ans = 0; 
    else dim = (int)squarer;
    
    if(ans){
      for(k = i = 0; i < dim; i++)
	for(j = 0; j < dim; j++) square[i][j] = str[k++];

      for(k = i = 0; i < dim; i++)
	for(j = 0; j < dim; j++) if(square[i][j] != str[k++]) ans = 0;

      for(k = i = 0; i < dim; i++)
	for(j = 0; j < dim; j++) if(square[j][i] != str[k++]) ans = 0;

      for(k = 0, i = dim-1; i >= 0; i--)
	for(j = dim-1; j >= 0; j--) if(square[i][j] != str[k++]) ans = 0;

      for(k = 0, i = dim-1; i >= 0; i--)
	for(j = dim-1; j >= 0; j--) if(square[j][i] != str[k++]) ans = 0;
				    
      /*
      for(i = 0; i < dim; i++){
	for(j = 0; j < dim; j++) printf("%c ", square[i][j]);
	printf("\n");
      }
      */
    }
    //printf("%s, %d\n", str, ans);
    printf("Case #%d:\n", caso++);
    if(ans) printf("%d\n", dim);
    else printf("No magic :(\n");
  }



  return 0;
}
