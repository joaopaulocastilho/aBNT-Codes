#include <stdio.h>

#define MAX 12
#define GEST 7 * 40
#define tint(c) (c - '0')
#define bis(y) ( (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) )

int mDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dSigns[][4] = {{21, 1, 19, 2},
		  {20, 2, 20, 3},
		  {21, 3, 20, 4},
		  {21, 4, 21, 5},
		  {22, 5, 21, 6},
		  {22, 6, 22, 7},
		  {23, 7, 21, 8},
		  {22, 8, 23, 9},
		  {24, 9, 23, 10},
		  {24, 10, 22, 11},
		  {23, 11, 22, 12},
		  {23, 12, 31, 12},
		  {01, 01, 20, 01}};

char nSigns[][20] = {{"aquarius"},
	       {"pisces"},
	       {"aries"},
	       {"taurus"},
	       {"gemini"},
	       {"cancer"},
	       {"leo"},
	       {"virgo"},
	       {"libra"},
	       {"scorpio"},
	       {"sagittarius"},
	       {"capricorn"},
	       {"capricorn"}};

int main(void){
  int i, n, d, m, y, cont = 1;
  char str[MAX];
  
  scanf("%d ", &n);
  while(n--){
    scanf("%s ", str);
    d = tint(str[2]) * 10 + tint(str[3]);
    m = tint(str[0]) * 10 + tint(str[1]);
    y = tint(str[4]) * 1000 + tint(str[5]) * 100 + tint(str[6]) * 10 + tint(str[7]);

    for(i = 0; i < GEST; i++){
      mDays[2] = bis(y) ? 29 : 28;
      d++;
      if(d > mDays[m]){d = 1; m++;}
      if(m > 12){m = 1; y++;}
    }
    
    printf("%d %.2d/%.2d/%.4d ", cont++, m, d, y);
    for(i = 0; i < 13; i++)
      if( (d >= dSigns[i][0] && m == dSigns[i][1]) || (d <= dSigns[i][2] && m == dSigns[i][3])){
	printf("%s\n", nSigns[i]);
	break;
      }
  }
  
  return 0;
}
