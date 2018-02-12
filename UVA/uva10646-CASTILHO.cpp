#include <stdio.h>

#define MAX 112

struct card { char numb, suit; };

int value_card(card n) {
  char value = n.numb;
  if (value == 'A' || value == 'K' || value == 'Q' || value == 'J'
      || value == 'T') return 10;
  return value - '0';
}

int main(void) {
  int i, n, y, teste, topop, topoh;
  card pile[MAX], hand[MAX], current;
  scanf("%d", &n);
  for (teste = 1; teste <= n; teste++) {
    for (topop = i = 0; i < 27; i++) {
      scanf(" %c%c", &pile[topop].numb, &pile[topop].suit);
      topop++;
    }
    for (topoh = i = 0; i < 25; i++) {
      scanf(" %c%c ", &hand[topoh].numb, &hand[topoh].suit);
      topoh++;
    }
    for (y = 0, i = 0; i < 3; i++) {
      current = pile[--topop];
      // printf("VALUE = %d\n", value_card(current));
      y += value_card(current);;
      topop -= (10 - value_card(current));
    }
    for (i = 0; i < 25; i++) pile[topop++] = hand[i];
    printf("Case %d: %c%c\n", teste, pile[y - 1].numb, pile[y - 1].suit);
  }
  return 0;
}
