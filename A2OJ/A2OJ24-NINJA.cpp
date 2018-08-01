#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, first, t, n, wa, wb, found;
  char word[15], wordb[MAX][21], worda[MAX][21];
  
  scanf("%d ", &t);
  while(t--){
    scanf("%d ", &n);
    for(wa = wb = found = 0; n; n--){
      scanf("%s ", word);
      if(word[0] != '#') found = 1;
      if(found) strcpy(worda[wa++], word);
      else strcpy(wordb[wb++], word);
    }
    for(first = i = 1; i < wa; i++){
      if(first) first = 0;
      else printf(" ");
      printf("%s", worda[i]);
    }
    if(found){
      if(first) first = 0;
      else printf(" ");
      printf("%s", worda[0]);
    }
    for(i = 0; i < wb; i++){
      if(first) first = 0;
      else printf(" ");
      printf("%s", wordb[i]);
    }
    printf("\n");
  }

  return 0;
}
