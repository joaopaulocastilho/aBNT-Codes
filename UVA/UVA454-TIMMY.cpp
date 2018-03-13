#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

#define MAX 1123

char linha[MAX];
string vlinha;
vector<string> matrix;
vector<string> nomatrix;
map< string, string > mapa;
set<string> cjt;

int limpa(){
  int len = strlen(linha);
  for(int i = 0; i < len; i++){
    if(linha[i] == ' '){
      for(int j = i; j < len; j++)
	linha[j] = linha[j+1];
      i--;
      len--;
    }
  }
  return len;
}

int main(void){
  int tc, len, found;
  string aux;
  scanf("%d", &tc);
  getchar(); getchar();
  while(tc--){
    matrix.clear();
    nomatrix.clear();
    cjt.clear();
    while(fgets(linha, MAX, stdin) && linha[0] != '\n'){
      aux.clear();
      len = strlen(linha);
      linha[--len] = '\0';
      for(int i = 0; i < len; i++)
	aux.push_back(linha[i]);
      cjt.insert(aux);
    }
    for(set<string>::iterator it = cjt.begin(); it != cjt.end(); ++it){
      vlinha.clear();
      aux.clear();
      memset(linha, 0, sizeof(linha));
      aux = (*it);
      for(int i = 0; i < aux.size(); i++)
	linha[i] = aux[i];
      len = limpa();
      for(int i = 0; i < len; i++)
	vlinha.push_back(linha[i]);
      sort(vlinha.begin(), vlinha.end());
      matrix.push_back(vlinha);
      nomatrix.push_back(aux);
    }
    for(vector<string>::iterator vvit = matrix.begin(); vvit != matrix.end(); ++vvit){
      for(vector<string>::iterator vvit2 = vvit+1; vvit2 != matrix.end(); ++vvit2){
	found = 1;
	if( vvit->size() != vvit2->size()) found = 0;
	for(int i = 0; i < vvit->size() && found; i++) if((*vvit)[i] != (*vvit2)[i]){ found = 0; break; }
	if(found){
	  string original = nomatrix[(vvit - matrix.begin())];
	  string original2 = nomatrix[(vvit2 - matrix.begin())];
	  for(int k = 0; k < original.size(); k++){
	    printf("%c", original[k]);
	  }
	  printf(" = ");
	  for(int k = 0; k < original2.size(); k++){
	    printf("%c", original2[k]);
	  }
	  printf("\n");
	}
      }
    }
    if(tc >= 1)
      printf("\n");
  }
  return 0;
}
