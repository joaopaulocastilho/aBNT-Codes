#include <cstdio>
#include <cstdlib>

int v[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leap(int year){
  if(((year % 4) == 0 && (year % 100)) || (year % 400) == 0)
    return 1;
  return 0;
}

int main(void){
  int tc, count, month, day, year;
  char m[3], d[3], y[5];
  scanf("%d", &tc);
  for(int i = 1; i <= tc; i++){
    count = 40 * 7;
    scanf(" %c%c%c%c%c%c%c%c", &m[0], &m[1], &d[0], &d[1], &y[0], &y[1], &y[2], &y[3]);
    month = atoi(m);
    day = atoi(d);
    year = atoi(y);
    while(count){
      if(count > (month == 2 ? (leap(year) ? v[month]+1 : v[month]) : v[month]) - day){
	count -= ((month == 2 ? (leap(year) ? v[month]+1 : v[month]) : v[month])- day) + 1;
	month++; day = 1;
	if(month > 12){ year++; month = 1; }
      }
      else{
	count--; day++;
	if(day > (month == 2 ? (leap(year) ? v[month]+1 : v[month]) : v[month])){ day = 1; month++;
	  if(month > 12) { year++; month = 1; }
	}
      }
    }
    printf("%d %.2d/%.2d/%.4d ", i, month, day, year);
    if((month == 1 && day >= 21) || (month == 2 && day <= 19))
      printf("aquarius\n");
    if((month == 2 && day >= 20) || (month == 3 && day <= 20))
      printf("pisces\n");
    if((month == 3 && day >= 21) || (month == 4 && day <= 20))
      printf("aries\n");
    if((month == 4 && day >= 21) || (month == 5 && day <= 21))
      printf("taurus\n");
    if((month == 5 && day >= 22) || (month == 6 && day <= 21))
      printf("gemini\n");
    if((month == 6 && day >= 22) || (month == 7 && day <= 22))
      printf("cancer\n");
    if((month == 7 && day >= 23) || (month == 8 && day <= 21))
      printf("leo\n");
    if((month == 8 && day >= 22) || (month == 9 && day <= 23))
      printf("virgo\n");
    if((month == 9 && day >= 24) || (month == 10 && day <= 23))
      printf("libra\n");
    if((month == 10 && day >= 24) || (month == 11 && day <= 22))
      printf("scorpio\n");
    if((month == 11 && day >= 23) || (month == 12 && day <= 22))
      printf("sagittarius\n");
    if((month == 12 && day >= 23) || (month == 1 && day <= 20))
      printf("capricorn\n");
  }
  return 0;
}
