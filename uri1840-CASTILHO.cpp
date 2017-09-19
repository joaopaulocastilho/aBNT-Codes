#include <stdio.h>
#include <string.h>
//#define DEBP
typedef struct{
  char carta;
  char naipe;
}carta_t;

int modulo(int a){
  if(a < 0) return a*-1;
  else return a;
}

char define_manilha(char a){
  if(a == '7') return 'Q';
  if(a == 'Q') return 'J';
  if(a == 'J') return 'K';
  if(a == 'K') return 'A';
  if(a == 'A') return '2';
  return a+1;
}

int peso_carta(carta_t a, char manilha){
  if(a.carta == manilha){
    if(a.naipe == 'C') return 1000;
    if(a.naipe == 'H') return 900;
    if(a.naipe == 'S') return 800;
    if(a.naipe == 'D') return 700;
  }
  if(a.carta == 'Q') return 70;
  if(a.carta == 'J') return 80;
  if(a.carta == 'K') return 90;
  if(a.carta == 'A') return 100;
  if(a.carta == '2') return 110;
  if(a.carta == '3') return 120;
  return a.carta-'0';
}

int main(void){
  int n, i, j, faz[4], vrodada[4], peso, maior, fez, menor, flag=0;
  carta_t vira, manilha, jogada;
  char jogadores[4][15];
  memset(vrodada, 0, sizeof(vrodada));
  scanf("%d", &n);
  getchar();
  vira.carta = getchar();
  vira.naipe = getchar();
  manilha.carta = define_manilha(vira.carta);
  for(i=0; i<4; i++){
    getchar();
    scanf("%s", jogadores[i]);
    scanf("%d", &faz[i]);
  }
  for(i=0; i<n; i++){
    peso = 0;
    maior = 0;
    for(j=0; j<4; j++){
      getchar();
      scanf("%c%c", &jogada.carta, &jogada.naipe);
      peso = peso_carta(jogada, manilha.carta);
#ifdef DEBP
      printf("carta == %c%c\n", jogada.carta, jogada.naipe);
#endif
      if(peso > maior){
	fez = j;
	maior = peso;
      }
    }
    vrodada[fez]++;
#ifdef DEBP
    printf("FEZ = %d, JA FEZ = %d\n", fez, vrodada[fez]);
#endif
  }
  menor = modulo(vrodada[0]-faz[0]);
  for(i=0; i<4; i++){
    if(menor > modulo(vrodada[i]-faz[i])){
      menor = modulo(vrodada[i]-faz[i]);
      fez = i;
    }
#ifdef DEBP
    printf("menor = %d\n", modulo(vrodada[i]-faz[i]));
#endif
  }
  for(i=0; i<4; i++){
    if(menor == modulo(vrodada[i]-faz[i])) flag++;
  }
  if(flag==1) printf("%s\n", jogadores[fez]);
  else printf("*\n");
  return 0;
}
