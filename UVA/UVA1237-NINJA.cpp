#include <stdio.h>
#include <string.h>

#define MAX 11234
#define MAXNAME 31

typedef struct{
  char name[MAXNAME];
  int low, high;
}car_t;

int main(void){
  int i, t, n, q, query, found, first = 1;
  car_t makers[MAX];
  char ans[MAXNAME];

  scanf("%d ", &t);
  while(t--){
    scanf("%d ", &n);
    for(i = 0; i < n; i++)
      scanf("%s %d %d ", makers[i].name, &makers[i].low, &makers[i].high);
    scanf("%d ", &q);
    if(first) first = 0;
    else printf("\n");
    while(q--){
      scanf("%d ", &query);
      for(found = i = 0; i < n; i++){
	if(query >= makers[i].low && query <= makers[i].high){
	  found++;
	  strcpy(ans, makers[i].name);
	}
      }
      printf("%s\n", found != 1 ? "UNDETERMINED" : ans);
    }
  }
}
