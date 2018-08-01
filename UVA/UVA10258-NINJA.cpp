#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 112

typedef struct{
  int id, solved, penal, probTimes[12], probSolves[12];
}comp_t;

bool cmp(comp_t a, comp_t b){
  if(a.solved != b.solved) return a.solved > b.solved;
  if(a.penal != b.penal) return a.penal < b.penal;
  return a.id < b.id;
}

int main(void){
  int i, id, prob, time, t, first = 1;
  char op, line[MAX];
  
  scanf("%d ", &t);
  while(t--){
    vector <comp_t> comps(MAX);
    for(i = 0; i < MAX; i++){
      comps[i].id = comps[i].solved = comps[i].penal = 0;
      memset(comps[i].probTimes, 0, sizeof(comps[i].probTimes));
      memset(comps[i].probSolves, 0, sizeof(comps[i].probSolves));
    }

    while(fgets(line, MAX, stdin) && line[0] != '\n'){
      sscanf(line, "%d %d %d %c ", &id, &prob, &time, &op);
      comps[id].id = id;
      if(op == 'R' || op == 'U' || op == 'E') continue;
      else if(op == 'I' && !comps[id].probSolves[prob])
	comps[id].probTimes[prob] += 20;
      else if(!comps[id].probSolves[prob]){
	comps[id].penal += comps[id].probTimes[prob] + time;
	comps[id].probSolves[prob] = 1;
	comps[id].solved++;
      }
    }
    sort(comps.begin(), comps.end(), cmp);
    if(first) first = 0;
    else printf("\n");
    for(i = 0; i < MAX; i++)
      if(comps[i].id)
	printf("%d %d %d\n", comps[i].id, comps[i].solved, comps[i].penal); 
  }

  return 0;
}
