#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

#define MAX 60

typedef struct{
  int x, y, z;
}op_t;

op_t op[MAX];

int operate(int x, char c, int y, int z){
  switch (c){
    case '+': return x + y == z;
    case '-': return x - y == z;
    case '*': return x * y == z;
    case 'I': return x * y != z && x + y != z && x - y != z;
  }
}

int main(void){
  int t, righta, tmpi;
  char tmps[MAX], tmpc;
  map <string, int> players;

  while(scanf("%d", &t) != EOF){
    righta = 0; players.clear();
    memset(op, 0, sizeof(op));
    for(int i = 0; i < t; i++)
      scanf("%d %d=%d\n", &op[i].x, &op[i].y, &op[i].z);
    for(int i = 0; i < t; i++){
      scanf("%s %d %c\n", tmps, &tmpi, &tmpc);
      if(operate(op[tmpi-1].x, tmpc, op[tmpi-1].y, op[tmpi-1].z)){
        righta++;
        players[tmps] = 1;
// printf("%s acertou pq %d%c%d é %d\n", tmps, op[tmpi-1].x, tmpc, op[tmpi-1].y, op[tmpi-1].z);
      }
      else{
        players[tmps] = 0;
// printf("%s errou pq %d%c%d n é %d\n", tmps, op[tmpi-1].x, tmpc, op[tmpi-1].y, op[tmpi-1].z);
      }
    }
    if(righta == 0) printf("None Shall Pass!\n");
    else if(righta == t) printf("You Shall All Pass!\n");
    else{
      int first = 1;
      for(map<string,int>::iterator it = players.begin(); it != players.end(); it++){
        if(it->second) continue;
        if(!first) printf(" ");
        else first = 0;
        printf("%s", it->first.c_str());
      }
      printf("\n");
    }
  }

  return 0;
}
