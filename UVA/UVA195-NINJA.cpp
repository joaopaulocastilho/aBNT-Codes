#include <stdio.h>
#include <string.h>
#include <set>
#include <string>

#define MAX 112345
#define MAX2 312

using namespace std;

set <string> s;
char alfaMod[MAX2][2];

void permutate(char *str, int l, int r){
  //printf("S -> %s\n", str);
  if(s.find(str) != s.end() || l > r) return;
  for(int i = l; i <= r; i++){
    swap(str[l], str[i]);
    permutate(str, l+1, r);
    swap(str[l], str[i]);
  }
  s.insert(str);
}

int main(void){
  int i, j, k, n, end;
  char str[MAX], tmp;

  memset(alfaMod, 0, sizeof(alfaMod));
  for(i = 'a', j = 1, k = 0; i <= 'z'; i++, j++, k++) {
    alfaMod[i][0] = ' ' - j;
    alfaMod[i - ' '][0] = k;
    //printf("Tira %d\n", i - alfaMod[i][0]);
  }
  //for(i = 'A'; i <= 'Z'; i++) printf("Soma %d\n", i + alfaMod[i][0]);
  
  scanf("%d ", &n);
  while(n--){
    s.clear();
    scanf("%s ", str);
    //printf("ATU: %s\n", str);
    end = strlen(str);
    for(i = 0; i < end; i++){
      //printf("char atual: %c\n", str[i]);
      tmp = str[i];
      //printf("c: %d m:%d\n",str[i],  alfaMod[str[i]][0]);
      if(str[i] >= 'a') str[i] -= alfaMod[str[i]][0]; 
      else str[i] += alfaMod[str[i]][0];
      alfaMod[str[i]][1] = tmp;
      //printf("%d\n", str[i]);
    }
    permutate(str, 0, end-1);
    for(set <string>::iterator it = s.begin(); it != s.end(); it++){
      for(i = 0; i < (int)(*it).length(); i++){
	printf("%c", alfaMod[(*it)[i]][1]);
      }
      printf("\n");
    }
  }
  
  return 0;
}
