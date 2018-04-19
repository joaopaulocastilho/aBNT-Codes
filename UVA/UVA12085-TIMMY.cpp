#include <cstdio>
#include <cstring>

#define MAX 21

char* itoa(int value, char* result, int base) {
  // check that the base if valid
  if (base < 2 || base > 36) { *result = '\0'; return result; }

  char* ptr = result, *ptr1 = result, tmp_char;
  int tmp_value;

  do {
    tmp_value = value;
    value /= base;
    *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
  } while ( value );

  // Apply negative sign
  if (tmp_value < 0) *ptr++ = '-';
  *ptr-- = '\0';
  while(ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr--= *ptr1;
    *ptr1++ = tmp_char;
  }
  return result;
}

int pegue_dif(char num1[], char num2[]){
  int len = strlen(num1);
  for(int i = 0; i < len; i++)
    if(num1[i] != num2[i]){
      return i;
    }
  return 0;
}
int main(void){
  int tc, count = 1, num, primeiro, start, ant, first, len, dif;
  char buffer1[MAX], buffer2[MAX];
  while(scanf("%d", &tc), tc != 0){
    ant = -1; first = 1; start = 0;
    printf("Case %d:\n", count++);
    while(tc--){
      scanf("%d", &num);
      if(first){ first = 0; ant = num; continue; }
      if(num - 1 == ant){
	if(!start){ primeiro = ant; start = 1; }
	ant = num;
      }
      else{
	if(start){
	  start = 0;
	  itoa(ant, buffer1, 10);
	  itoa(primeiro, buffer2, 10);
	  dif = pegue_dif(buffer1, buffer2);
	  printf("0%d-", primeiro);
	  len = strlen(buffer1);
	  for(int i = dif; i < len; i++) printf("%c", buffer1[i]);
	  printf("\n");
	}
	else {
	  printf("0%d\n", ant);
	}
	ant = num;
	}
    }
    if(start){
      itoa(ant, buffer1, 10);
      itoa(primeiro, buffer2, 10);
      dif = pegue_dif(buffer1, buffer2);
      len = strlen(buffer1);
      printf("0%d-", primeiro);
      for(int i = dif; i < len; i++) printf("%c", buffer1[i]);
      printf("\n");
    }
    else printf("0%d\n", num);
    printf("\n");
  }
  return 0;
}
