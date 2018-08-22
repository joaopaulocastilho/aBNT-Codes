#include <stdio.h>
#include <string.h>

int NC;

int valido(int i){
  if(i == -1) return NC-1;
  if(i == NC) return 0;
  return i;
}

int main(void){
    int v[11234], i, count;

    scanf("%d", &NC);
    while(NC != 0){
        memset(v, 0, sizeof(v));
        count = 0;
        for(i = 0; i < NC; i++){
            scanf("%d", &v[i]);
        }
        for(i = 0; i < NC; i++){
	  if(((v[valido(i-1)]) > v[i] && v[i] < v[valido(i+1)]) ||
	     (v[valido(i-1)] < v[i] && v[i] > v[valido(i+1)]))
	    count++;
        }
        printf("%d\n", count);
        scanf("%d", &NC);
    }
}
