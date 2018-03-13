#include <cstdio>
#include <cstring>

#define MAX 112

int main(void){
  char linha[MAX];
  int len, palin;
  while(fgets(linha, MAX, stdin)){
    len = strlen(linha);
    linha[len-1] = '\0';
    if(strcmp(linha, "DONE") == 0) break;
    for(int i = 0; i < len-1; i++){
      if(linha[i] == ',' || linha[i] == ' ' || linha[i] == '.' || linha[i] == '!' || linha[i] == '?'){
	for(int j = i; j < len-1; j++)
	  linha[j] = linha[j+1];
	len--;
	i--;
      }
      else if(linha[i] >= 'A' && linha[i] <= 'Z') linha[i] += 32;
    }
    palin = 1;
    for(int i = 0, j = len-2; i < j; i++, j--)
      if(linha[i] != linha[j]) palin = 0;
    if(palin) printf("You won't be eaten!\n");
    else printf("Uh oh..\n");
  }
  return 0;
}
