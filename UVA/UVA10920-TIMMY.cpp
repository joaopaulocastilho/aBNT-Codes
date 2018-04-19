#include <cstdio>

int main(void){
  int line, column, sz, jump, ccount, dir;
  unsigned long long p, count;
  while(scanf("%d %llu", &sz, &p), sz + p != 0){
    column = line = (sz+1)/2;
    count = 1;
    jump = 1;
    ccount = 0;
    dir = 0;
    while(count < p){
      ccount++;
      if(dir == 0) line += jump;
      if(dir == 1) column -= jump;
      if(dir == 2) line -= jump;
      if(dir == 3) column += jump;
      count += jump;
      if(count < p ) dir = (dir+1) % 4;
      if(ccount == 2){ ccount = 0; jump++; }
    }
    while(count > p){
      if(dir == 0) line--;
      if(dir == 1) column++;
      if(dir == 2) line++;
      if(dir == 3) column--;
      count--;
    }
    printf("Line = %d, column = %d.\n", line, column);
  }
  return 0;
}
