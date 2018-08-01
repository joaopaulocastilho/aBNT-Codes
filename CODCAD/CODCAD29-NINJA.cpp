#include <stdio.h>
#include <string.h>

#define MAX 31
#define MAXX 500

int main(void){
  int i, end;
  char str[MAX], dic[MAXX];

  dic['A'] = 2;
  dic['B'] = 2;
  dic['C'] = 2;
  dic['D'] = 3;
  dic['E'] = 3;
  dic['F'] = 3;
  dic['G'] = 4;
  dic['H'] = 4;
  dic['I'] = 4;
  dic['J'] = 5;
  dic['K'] = 5;
  dic['L'] = 5;
  dic['M'] = 6;
  dic['N'] = 6;
  dic['O'] = 6;
  dic['P'] = 7;
  dic['Q'] = 7;
  dic['R'] = 7;
  dic['S'] = 7;
  dic['T'] = 8;
  dic['U'] = 8;
  dic['V'] = 8;
  dic['W'] = 9;
  dic['X'] = 9;
  dic['Y'] = 9;
  dic['Z'] = 9;
  
  scanf("%s", str);
  for(end = strlen(str), i = 0; i < end; i++){
    if(str[i] >= 'A' && str[i] <= 'Z') str[i] = dic[str[i]] + '0';;
  }
  printf("%s\n", str);
  return 0;
}
