#include <stdio.h>
#include <string.h>

#define MAX 1123456

int num_led(char a){
  switch(a){
  case '1': return 2; break;
  case '2': return 5; break;
  case '3': return 5; break;
  case '4': return 4; break;
  case '5': return 5; break;
  case '6': return 6; break;
  case '7': return 3; break;
  case '8': return 7; break;
  case '9': return 6; break;
  case '0': return 6; break;
  }
  return 0;
}

int main(void){
  char num[MAX];
  int n, cont, i;
  scanf("%d", &n);
  getchar();
  while(n--){
    cont = 0;
    memset(num, 0, sizeof(num));
    fgets(num, MAX, stdin);
    for(i=0; i<strlen(num); i++) cont+=num_led(num[i]);
    printf("%d leds\n", cont);
  }
  return 0;
}
