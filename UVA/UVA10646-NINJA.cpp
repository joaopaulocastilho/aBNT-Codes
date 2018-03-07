#include <stdio.h>
#include <string.h>

#define MAX 1123

typedef struct{
  char value, suit;
}card_t;

int value(card_t card){
  if(card.value >= '2' && card.value <= '9') return card.value - '0';
  else return 10;
}

int main(void){
  int n, i, j, end, x, y, count, take, caso = 1;
  char line[MAX];
  card_t deck[52];

  scanf("%d\n", &n);
  while(n--){
    y = 0;
    fgets(line, MAX, stdin);
    //printf("->%s\n", line);
    end = strlen(line);
    for(i = j = 0; i < end; i++){
      if(line[i] == ' ') continue;
      if(line[i] == 'S' || line[i] == 'D' || line[i] == 'H' || line[i] == 'C')
	deck[j++].suit = line[i];
      else deck[j].value = line[i];
    }
    //for(i = 0; i < 52; i++) printf("%c%c ", deck[i].value, deck[i].suit); 
    //printf("\n");
    for(count = 0; count < 3; count++){
      i = 26;
      while(deck[i].value == 'X') i--;
      x = value(deck[i]);
      //printf("%c -> %d\n",deck[i].value, x);
      y += x;
      take = 10-x + 1;
      for(j = 0; j < take; j++) deck[i--].value = 'X'; 
    }
    for(i = j = 0; j < y-1; i++){
      if(deck[i].value != 'X') j++;
    }
    //printf("%d\n", y);
    printf("Case %d: %c%c\n", caso++,  deck[i].value, deck[i].suit);
  }

  return 0;
}
