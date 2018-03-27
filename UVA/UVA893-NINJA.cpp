#include <stdio.h>

#define bis(x) ( ((x%4 == 0) && (x%100 != 0)) || (x % 400 == 0) )

int mDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void atualizaBis(int y){
  mDays[2] = bis(y) ? 29 : 28;
}

int main(void){
  int remDays, desc, d, m, y;

  while(scanf("%d %d %d %d", &remDays, &d, &m, &y), m){
    atualizaBis(y);
    while(remDays){
      desc = mDays[m] - d;
      if(remDays >= desc){
	remDays -= desc;
	d += desc;
      }
      if(remDays){
	remDays--; d++;
	if(d > mDays[m]){d = 1; m++;}
	if(m > 12){m = 1; y++; atualizaBis(y);}
      }
    }
    printf("%d %d %d\n", d, m, y);
  }

  return 0;
}
