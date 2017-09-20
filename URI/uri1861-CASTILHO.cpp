#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <string>
using namespace std;

#define MAX 112345

map <string, int> Mor;
map <string, int> Assas;

int cmp(const void *a, const void *b){
  return strcmp((char*)a, (char*)b);
}

int main(void){
  char kill[MAX][13], dead[MAX][13];
  int i, j;
  string str, str2;
  while(scanf("%s %s\n", kill[i], dead[i]) != EOF){
    str=dead[i];
    str2 = kill[i];
    Mor[str] = 1;
    Assas[str2]=0;
    i++;
  }
  qsort(kill, i, sizeof(kill[0]), &cmp);
  for(j=0; j<i; j++){
    str=kill[j];
    if(Mor[str] != 1) Assas[str] += 1;
  }
  printf("HALL OF MURDERERS\n"); 
  for(j=0; j<i; j++){
    str=kill[j];
    if(Assas[str]){
      printf("%s %d\n", kill[j], Assas[str]);
      Assas[str]=0;
    }
  }
  return 0;
}
