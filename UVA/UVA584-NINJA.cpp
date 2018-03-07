#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, j, end, ans, roll, frame;
  char str[MAX], line[MAX];
  
  while(fgets(str, MAX, stdin), str[0] != 'G'){
    for(end = strlen(str), i = j = 0; i < end; i++)
      if(str[i] != ' ') line[j++] = str[i];
    line[j-1] = 0;
    end = strlen(line);
    for(frame = roll = ans = i = 0; i < end; i++, roll ^= 1){
      if(roll == 0) frame++;
      if(frame == 11) continue;
      if(line[i] == 'X'){
	ans += 10;
	if(line[i+1] == '/' || line[i+2] == '/') ans += 10;
	else{
	  ans += line[i+1] == 'X' ? 10 : line[i+1] - '0';
	  ans += line[i+2] == 'X' ? 10 : line[i+2] - '0';
	}
	roll = 1;
      }
      else if(line[i] == '/'){ans += line[i+1] == 'X' ? 10 : line[i+1] - '0'; roll = 1;}
      else if(line[i+1] == '/') ans += 10;
      else ans += line[i] - '0';
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
