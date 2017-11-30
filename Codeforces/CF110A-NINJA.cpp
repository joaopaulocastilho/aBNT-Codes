#include <stdio.h>
#include <string.h>

#define MAX 20

int main(void){
  int i, luckd, ans = 1;
  char num[MAX];

  scanf("%s", num);
  for(luckd = i = 0; i < strlen(num); i++) if(num[i] == '4' || num[i] == '7') luckd++;
  do{
    if((luckd % 10 != 7) && (luckd % 10 != 4)) ans = 0;		 
  }while(luckd /= 10);
  printf("%s\n", ans ? "YES" : "NO");

  return 0;
}
