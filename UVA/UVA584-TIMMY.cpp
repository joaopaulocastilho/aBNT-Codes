#include <cstdio>
#include <cstring>

#define MAX 112

int main(void){
  char linha[MAX];
  int j, i, len, jogada[11], strike[10], jogada1[11], spare[11];
  
  while(fgets(linha, MAX, stdin), linha[0] != 'G'){
    int ans = 0;
    for(i = 0; i < 11; i++) jogada[i] = strike[i] = spare[i] = jogada1[i] = 0;
    len = strlen(linha);
    j = 0;
    for(i = 0; j < 10; i+=2){
      if(linha[i] == 'X'){
	jogada[j] = 10;
	jogada1[j] = 10;
	strike[j++] = 1;
      }
      else if(linha[i+2] == '/'){
	jogada[j] = 10;
	spare[j] = 1;
	jogada1[j++] = (linha[i]-'0');
	i+= 2;
      }
      else{
	jogada[j] = (linha[i]-'0') + (linha[i+2] - '0');
	jogada1[j++] = (linha[i]-'0');
	i+= 2;
      }
    }
    if(strike[j-1] == 1){
      if(linha[i] == 'X'){
	jogada[j] = 10;
	jogada1[j] = 10;
	if(linha[i+2] == 'X') jogada[j]+= 10;
	else jogada[j] += linha[i+2] - '0';
      }
      else if(linha[i+2] == '/'){
	jogada[j] = 10;
	jogada1[j] = linha[i] - '0';
      }
      else{
	jogada[j] = (linha[i]-'0') + (linha[i+2] - '0');
	jogada1[j] = linha[i] - '0';
      }
    }
    if(spare[j-1] == 1){
      if(linha[i] == 'X') jogada[j] = 10;
      else jogada[j] = (linha[i] - '0');
    }
    for(i = 0; i < 9; i++){
      ans += jogada[i];
      if(strike[i]){
	if(strike[i+1])
	   ans += jogada[i+1] + jogada1[i+2];
	else
	  ans += jogada[i+1];
      }
      if(spare[i]){
	ans+= jogada1[i+1];
      }
      //printf("%d ", ans);
    }
    ans += jogada[i];
    if(strike[i] || spare[i]) ans += jogada[i+1];
    //for(i = 0; i < 11; i++) printf("%d ", jogada[i]);
    printf("%d\n", ans);
  }  
  return 0;
}
