#include <cstdio>
#include <cstring>

#define MAX 21

int reverso(char a, char b){
  switch(a){
  case 'A': return b == 'A' ? 1 : 0; break;
  case 'E': return b == '3' ? 1 : 0; break;
  case 'H': return b == 'H' ? 1 : 0; break;
  case 'I': return b == 'I' ? 1 : 0; break;
  case 'J': return b == 'L' ? 1 : 0; break;
  case 'L': return b == 'J' ? 1 : 0; break;
  case 'M': return b == 'M' ? 1 : 0; break;
  case 'O': return b == 'O' ? 1 : 0; break;
  case 'S': return b == '2' ? 1 : 0; break;
  case 'T': return b == 'T' ? 1 : 0; break;
  case 'U': return b == 'U' ? 1 : 0; break;
  case 'V': return b == 'V' ? 1 : 0; break;
  case 'W': return b == 'W' ? 1 : 0; break;
  case 'X': return b == 'X' ? 1 : 0; break;
  case 'Y': return b == 'Y' ? 1 : 0; break;
  case 'Z': return b == '5' ? 1 : 0; break;
  case '1': return b == '1' ? 1 : 0; break;
  case '2': return b == 'S' ? 1 : 0; break;
  case '3': return b == 'E' ? 1 : 0; break;
  case '5': return b == 'Z' ? 1 : 0; break;
  case '8': return b == '8' ? 1 : 0; break;
  }
  return 0;
}
  

int main(void){
  char linha[MAX];
  int len, i, j, mirrored, palin, flag = 1;
  while(scanf(" %s", linha) != EOF){
    if(flag) flag = 0;
    else printf("\n");
    len = strlen(linha);
    mirrored = 1;
    palin = 1;
    for(i = 0, j = len-1; i < j; i++, j--){
      if(!reverso(linha[i], linha[j])) mirrored = 0;
      if(linha[i] != linha[j]) palin = 0;
    }
    if(i == j)
      if(!reverso(linha[i], linha[j])) mirrored = 0;
    if(palin)
      if(mirrored)
	printf("%s -- is a mirrored palindrome.\n", linha);
      else printf("%s -- is a regular palindrome.\n", linha);
    else if(mirrored)
      printf("%s -- is a mirrored string.\n", linha);
    else
      printf("%s -- is not a palindrome.\n", linha);
      
  }
  printf("\n");
  return 0;
}
