#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>


using namespace std;

#define MAX 1123

typedef struct{
  int id, solved, error, maxtime;
  vector<int> s;
  vector<int> u;
} participante;

bool compare(participante a, participante b){
  if(a.solved != b.solved)
    return a.solved > b.solved;
  if(a.maxtime != b.maxtime)
    return a.maxtime < b.maxtime;
  return a.id < b.id;
}

int main(void){
  int i, j, tc;
  char cnum[MAX], line[MAX];
  int time, cont, prob;
  char l;
  vector<participante> p;
  vector<participante>::iterator it;
  vector<int>::iterator it2;
  scanf("%d ", &tc);
  while(tc--){
    p.clear();
    while(fgets(line, MAX, stdin) != NULL && line[0] != '\n'){
      for(i = 0, j = 0; line[i] != ' '; i++){
	cnum[j++] = line[i];
	cnum[j] = '\0';
      }
      i++;
      cont = atoi(cnum);
      for(j = 0; line[i] != ' '; i++){
	cnum[j++] = line[i];
	cnum[j] = '\0';
      }
      i++;
      prob = atoi(cnum);
      for(j = 0; line[i] != ' '; i++){
	cnum[j++] = line[i];
	cnum[j] = '\0';
      }
      i++;
      time = atoi(cnum);
      l = line[i];
      for(it = p.begin(); it != p.end(); ++it){
	if((*it).id == cont){
	  it2 = find((*it).s.begin(), (*it).s.end(), prob);
	  if(it2 == (*it).s.end()){
	    if(l == 'I'){ (*it).error++; (*it).u.push_back(prob); }
	    else if(l == 'C'){
	      (*it).s.push_back(prob);
	      (*it).solved++;
	      if(it->maxtime == 0) it->maxtime = time;
	      else (*it).maxtime += time;
	    }
	  }
	  break;
	}
      }
      if(it == p.end()){
	participante aux;
	aux.id = cont;
	if(l == 'C'){
	  aux.solved = 1;
	  aux.maxtime = time;
	  aux.error = 0;
	  aux.s.push_back(prob);
	}
	else if(l == 'I'){
	  aux.solved = 0;
	  aux.maxtime = 0;
	  aux.error = 1;
	  aux.u.push_back(prob);
	}
	else{
	  aux.solved = 0;
	  aux.maxtime = 0;
	  aux.error = 0;
	}
	p.push_back(aux);
      }
	//for(i = 0; i < p.size(); i++)
	// printf("ID: %d SOLVED: %d ERRORS: %d MAXTIME: %d PROBLEMS S: %d PROBLEMS U:%d\n", p[i].id, p[i].solved, p[i].error, p[i].maxtime, p[i].s.size(), p[i].u.size());
	//printf("\n");
    }
    for(it = p.begin(); it != p.end(); ++it){
      for(it2 = it->u.begin(); it2 != it->u.end(); ++it2){
	if(find(it->s.begin(), it->s.end(), (*it2)) != it->s.end()) it->maxtime += 20;
      }	
    }
    //for(i = 0; i < (int)p.size(); i++)
    //printf("ID: %d SOLVED: %d ERRORS: %d MAXTIME: %d PROBLEMS S: %d PROBLEMS U:%d\n", p[i].id, p[i].solved, p[i].error, p[i].maxtime, (int)p[i].s.size(), (int)p[i].u.size());
    //printf("\n");
    sort(p.begin(), p.end(), compare);
    for(it = p.begin(); it != p.end(); ++it){
      printf("%d %d %d\n", it->id, it->solved, it->maxtime);
    }
    if(tc && (int)p.size() != 0) printf("\n");
  }
  return 0;
}
