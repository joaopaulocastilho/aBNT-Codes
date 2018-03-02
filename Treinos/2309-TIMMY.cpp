#include <cstdio>

#define MAX 1123456

int main(void){
  int i, j, counta, countb, cartas[MAX], ct, a, b, carta;
  counta = countb = 0;
  scanf("%d", &ct);
  while(ct--){
    a = b = 0;
    for(i = 0; i < 6; i++){
      scanf("%d", &carta);
      if(carta < 4) carta+=13;
      else if(carta == 11) carta++;
      else if(carta == 12) carta--;
      cartas[i] = carta;
    }
    for(i = 0, j = 3; i < 3; i++, j++){
      if(cartas[i] >= cartas[j]) a++;
      else if(cartas[i] < cartas[j]) b++;
    }
    if(a > b) counta++;
    else countb++;
  }
  printf("%d %d\n", counta, countb);
  return 0;
}
