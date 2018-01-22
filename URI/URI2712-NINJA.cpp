#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void){
  char str[MAX];
  int i, n, valido;

  scanf("%d ", &n);
  while(n--){
    valido = 1;
    fgets(str, MAX, stdin);
    str[strlen(str) - 1] = '\0';
    if(strlen(str) != 8) valido = 0;
    else{
      for(i = 0; i < 3; i++) if (str[i] < 'A' || str[i] > 'Z') valido = 0;
      if(str[i] != '-') valido = 0;
      for(i++; i < 8; i++) if(str[i] < '0' || str[i] > '9') valido = 0;
    }
    if(valido){
      if(str[7] == '1' || str[7] == '2') printf("MONDAY\n"); 
      else if(str[7] == '3' || str[7] == '4') printf("TUESDAY\n");
      else if(str[7] == '5' || str[7] == '6') printf("WEDNESDAY\n");
      else if(str[7] == '7' || str[7] == '8') printf("THURSDAY\n");
      else printf("FRIDAY\n");
    }
    else printf("FAILURE\n");
  }

  return 0;
}
