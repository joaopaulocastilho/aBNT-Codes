#include <cstdio>
#include <cstring>

#define MAX 20

int main(void){
  int mao[4][MAX], pontos = 0, flag = 0, cartas[4], inaipe, icarta, stopped[4];
  char naipe, carta;
  while(!flag){
    pontos = 0;
    memset(mao, 0, sizeof(mao));
    memset(cartas, 0, sizeof(cartas));
    memset(stopped, 0, sizeof(stopped));
    for(int i = 0; i < 13 && flag == 0; i++){
      if(scanf(" %c%c", &carta, &naipe) == EOF){ flag = 1; break; }
      if(carta == 'Q'){ icarta = 10; pontos += 2; }
      else if(carta == 'T'){ icarta = 14; }
      else if(carta == 'J'){ icarta = 11; pontos++; }
      else if(carta == 'K'){ icarta = 12; pontos += 3; }
      else if(carta == 'A'){ icarta = 13; pontos += 4; }
      else icarta = carta - '0';
      if(naipe == 'S') inaipe = 0;
      else if(naipe == 'H') inaipe = 1;
      else if(naipe == 'D') inaipe = 2;
      else if(naipe == 'C') inaipe = 3;
      mao[inaipe][icarta] = 1;
    }
    if(flag) break;
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 15; j++)
	if(mao[i][j] == 1){ cartas[i]++; }
    }
    for(int i = 0; i < 4; i++){
      if(mao[i][13] || (mao[i][12] && cartas[i] >= 2) || (mao[i][10] && cartas[i] >= 3)) stopped[i] = 1;
      if(mao[i][12] && cartas[i] == 1) pontos--;
      if(mao[i][10] && cartas[i] <= 2) pontos--;
      if(mao[i][11] && cartas[i] <= 3) pontos--;
    }
    if(pontos >= 16 && stopped[0] && stopped[1] && stopped[2] && stopped[3]){ printf("BID NO-TRUMP\n"); continue; }
    for(int i = 0; i < 4; i++){
      if(cartas[i] == 2) pontos++;
      if(cartas[i] == 1) pontos += 2;
      if(cartas[i] == 0) pontos += 2;      
    }
    if(pontos < 14){ printf("PASS\n"); continue; }
    else{
      int maior = -1, mnum = -1;
      for(int i = 0; i < 4; i++) if(cartas[i] > mnum){ maior = i; mnum = cartas[i]; }
      printf("BID %c\n", maior == 0 ? 'S' : maior == 1 ? 'H' : maior == 2 ? 'D' : 'C');
    }
  }
  return 0;
}
