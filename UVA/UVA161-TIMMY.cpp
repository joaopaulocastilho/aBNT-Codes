#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 112
#define GREEN 0
#define OTHER 1

typedef struct{
  int green;
  int other;
  int time;
  int state;
} farol;

int main(void){
  farol v[MAX];
  int green, other, count, finish, num, next, i, j;
  finish = 0;
  while(!finish){
    scanf("%d", &num);
    if(num == 0){ finish = 1; continue; }
    memset(v, 0, sizeof(v));
    count = 0;
    next = 0;
    while(!next){
      if(num == 0){ next = 1; continue; }
      green = num - 5;
      other = num + 5;
      v[count].green = green; v[count].other = other; v[count].state = GREEN; v[count++].time = 0;
      scanf("%d", &num);
    }
    int start = MAX;
    for(i = 0; i < count; i++)
      start = min(v[i].green, start);
    for(j = 0; j < count; j++){
      v[j].time = start;
      if(v[j].time == v[j].green){ v[j].state = OTHER; v[j].time = 0; }
    }
    for(i = start+1; i <= 5 * 3600; i++){
      for(j = 0; j < count; j++){
	v[j].time++;
	if(v[j].state == GREEN && v[j].time == v[j].green){ v[j].state = OTHER; v[j].time = 0; }
	else if(v[j].state == OTHER && v[j].time == v[j].other){v[j].state = GREEN; v[j].time = 0; }
      }
      int tv = 1;
      for(j = 0; j < count; j++){
	if(v[j].state != GREEN) tv = 0;
      }
      if(tv){
	int horas = 0, minutos = 0, segundos = 0;
	for(j = i; j >= 60;){
	  if(j >= 3600){ horas++; j -= 3600; }
	  else if(j >= 60){ minutos++; j -= 60; }
	}
	segundos = j;
	printf("%02d:%02d:%02d\n", horas, minutos, segundos);
	break;
      }
    }
    if(i > 5*3600) printf("Signals fail to synchronise in 5 hours\n");
  }
  //printf("\n");
  return 0;
}
