#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

typedef pair <int, int> ii;
typedef pair <double, ii> dii;
typedef unsigned long long ull;

int main(void){
  int t, c, leitura;
  ull ac = 0, multa = 0, dia = 0;
  priority_queue < dii, vector <dii>, less <dii> > Q;
  while((leitura = scanf("%d %d", &t, &c)) != EOF || !Q.empty()){
    if(leitura != EOF){
      multa += c;
      Q.push(dii(double(c)/t, ii(t, c)));
    }
    if(dia == 0 && !Q.empty()){
      dia = Q.top().second.first;
      multa -= Q.top().second.second;
      Q.pop();
    }
    if(leitura == EOF && dia){
      while(!Q.empty()){
	ac += multa * dia;
	dia = 0;
	if(!Q.empty()){
	  dia = Q.top().second.first;
	  multa -= Q.top().second.second;
	  Q.pop();
	}
      } 
    }
    dia--; ac += multa;
  }
  printf("%llu\n", ac);
  return 0;
}
