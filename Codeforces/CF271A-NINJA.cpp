#include <stdio.h>

int beautiful(int year){
  int i, dig[4], ans = 1;
  
  for(i = 0; i < 4; i++, year /= 10) dig[i] = year % 10;;
  if(dig[0] == dig[1] || dig[0] == dig[2] || dig[0] == dig[3] ||
     dig[1] == dig[2] || dig[1] == dig[3] ||dig[2] == dig[3])
    return 0;
  return 1;
}

int main(void){
  int year;
  
  scanf("%d", &year);
  do{
    year++;
  }while(!beautiful(year));
  printf("%d\n", year);
  
  return 0;
}
