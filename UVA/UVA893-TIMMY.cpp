#include <cstdio>

int leap(int num){
  if(((num % 4) == 0 && (num % 100) != 0) || (num % 400) == 0)
    return 1;
  return 0;
}

int v[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void){
  int count, day, month, year;
  while(scanf("%d %d %d %d", &count, &day, &month, &year), day != 0){
    while(count){
      //printf("%d %d %d %d\n", count, day, month, year);
      //if(!leap(year) && count >= 365){ year++; count -= 365; printf("Aumentei em um o ano: %d %d\n", year, count); }
      //else if(leap(year) && count >= 366){ year++; count -= 366; printf("Aumentei em um o ano, mas sou bissexto: %d %d\n", year, count); }
      if(count > (month == 2 ? (leap(year) ? v[month]+1 : v[month]) : v[month])){
	count -= ((month == 2 ? (leap(year) ? v[month]+1 : v[month]) : v[month]) - day)+1; day = 1; month++;
	//printf("Aumentei o mes: %d %d %d\n", month, day, count);
	if(month > 12){
	  month = 1; year++;
	  //printf("Aumentei o ano: %d %d %d\n", month, year, count);
	}
      }
      else{
	day++; count--;
	if(day > (month == 2 ? (leap(year) ? v[month]+1 : v[month]) : v[month])){
	  day = 1; month++;
	  //printf("Aumentei o mes: %d\n", month);
	}
	if(month > 12){
	  month = 1; year++;
	  //printf("Aumentei o ano: %d\n", year);
	}
      }
    }
    printf("%d %d %d\n", day, month, year);
  }

  return 0;
}
