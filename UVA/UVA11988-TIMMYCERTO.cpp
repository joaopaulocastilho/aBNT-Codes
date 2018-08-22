#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
  string line;
  string aux;
  vector<string> start;
  vector<string> end;
  while(getline(cin, line)){
    int put = 1;
    aux.clear();
    start.clear();
    end.clear();
    for(int i = 0; i < (int)line.size(); ++i){
      if(line[i] != '[' && line[i] != ']') aux.push_back(line[i]);
      if(line[i] == '['){
	if(aux.size() > 0){
	  if(put == 0) start.push_back(aux);
	  else end.push_back(aux);
	}
	put = 0;
	aux.clear();
      }
      if(line[i] == ']'){
	if(aux.size() > 0){
	  if(put == 0) start.push_back(aux);
	  else end.push_back(aux);
	}
	put = 1;
	aux.clear();
      }
    }
    if(aux.size() > 0){
      if(put == 0) start.push_back(aux);
      else end.push_back(aux);
      aux.clear();
    }
    if(start.size())
      for(vector<string>::iterator it = start.end()-1; it != start.begin()-1; --it) cout << (*it);
    if(end.size())
      for(vector<string>::iterator it = end.begin(); it != end.end(); ++it) cout << (*it);
    cout << "\n";      
  }
  return 0;
}
