#include <stdio.h>
#include <string.h>
#include <algorithm>

#define MAX 112
#define SUITER(c) (c) == 'S' ? 0 : ( (c) == 'H' ? 1 : ((c) == 'D' ? 2 : 3)) 

using namespace std;

typedef struct{
  char val, suit; 
}card_t;

typedef struct{
  int qtd, stopped;
}suit_t;

int main(void){
  int biggest, indbig, i, j,  end, allstop, total, alt;
  card_t hand[13];
  char line[MAX], suitsc[] = "SHDC";
  suit_t suits[4];
  
  while(fgets(line, MAX, stdin)){
    total = alt = 0;
    memset(suits, 0, sizeof(suits));
    end = strlen(line);
    for(i = j = 0; i < end; i++){
      if(line[i] == ' ') continue;
      if(line[i] == 'S' || line[i] == 'H' || line[i] == 'D' || line[i] == 'C'){
	if(line[i] == 'S') suits[SUITER('S')].qtd++;
	else if(line[i] == 'H') suits[SUITER('H')].qtd++;
	else if(line[i] == 'D') suits[SUITER('D')].qtd++;
	else suits[SUITER('C')].qtd++;
	hand[j++].suit = line[i];
      }
      else hand[j].val = line[i];
    }
    for(i = 0; i < 13; i++){
      if(hand[i].val == 'A'){
	total += 4;
	suits[SUITER(hand[i].suit)].stopped = 1;
      }
      else if(hand[i].val == 'K'){
	total += 3;
	if(suits[SUITER(hand[i].suit)].qtd > 1)
	  suits[SUITER(hand[i].suit)].stopped = 1;
	else total--;
      }
      else if(hand[i].val == 'Q'){
	total += 2;
	if(suits[SUITER(hand[i].suit)].qtd > 2)
	  suits[SUITER(hand[i].suit)].stopped = 1;
	else total --;
      }
      else if(hand[i].val == 'J'){
	total++;
	if(suits[SUITER(hand[i].suit)].qtd < 4) total--;
      }
    }
    for(indbig = biggest = i = 0, allstop = 1; i < 4; i++){
      if(suits[i].qtd > biggest){
	indbig = i;
	biggest = suits[i].qtd;
      }
      allstop &= suits[i].stopped;
      if(suits[i].qtd == 2) alt++;
      else if(suits[i].qtd == 1 || suits[i].qtd == 0) alt += 2;
    }
    
    if(total >= 16 && allstop) printf("BID NO-TRUMP\n");
    else if(total + alt < 14) printf("PASS\n");
    else printf("BID %c\n", suitsc[indbig]);

    //printf("%d\n", total + alt);
    //for(i = 0; i < 13; i++) printf("%c%c ", hand[i].val, hand[i].suit);
    //printf("\n");
    //printf("%d %d %d %d\n", suits[0].qtd, suits[1].qtd, suits[2].qtd, suits[3].qtd); 
  }
  return 0;
}
