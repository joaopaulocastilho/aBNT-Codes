#include <stdio.h>
#include <string.h>

#define MAX 31

char reverse(char c){
  switch(c){
  case 'E': return '3'; break;
  case 'S': return '2'; break;
  case 'Z': return '5'; break;
  case '2': return 'S'; break;
  case '3': return 'E'; break;
  case '5': return 'Z'; break;
  case 'J': return 'L'; break;
  case 'L': return 'J'; break;
  case 'A': return 'A'; break;
  case 'H': return 'H'; break;
  case 'I': return 'I'; break;
  case 'M': return 'M'; break;
  case 'O': return 'O'; break;
  case 'T': return 'T'; break;
  case 'U': return 'U'; break;
  case 'V': return 'V'; break;
  case 'W': return 'W'; break;
  case 'X': return 'X'; break;
  case 'Y': return 'Y'; break;
  case '1': return '1'; break;
  case '8': return '8'; break;
  }
  return ' ';
}

int main(void){
  int i, j, end, pali, reve;
  char str[MAX], str2[MAX];

  while(scanf("%s ", str) != EOF){
    end = strlen(str);
    for(pali = 1, i = 0, j = end-1; i <= j; i++, j--)
      if(str[i] != str[j]) pali = 0;
    for(i = 0; i < end; i++){
      str2[i] = reverse(str[i]);
    }
    for(reve = 1, i = 0, j = end-1; i < end; i++, j--)
      if(str[i] != str2[j] || reverse(str[i]) == ' ') reve = 0;
    printf("%s -- ", str);
    if(pali && reve) printf("is a mirrored palindrome.\n");
    else if(pali) printf("is a regular palindrome.\n");
    else if(reve) printf("is a mirrored string.\n");
    else printf("is not a palindrome.\n");
    printf("\n");
  } 

  return 0;
}
