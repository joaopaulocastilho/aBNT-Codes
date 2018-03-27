#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cstring>

using namespace std;

vector<string> ans;
set<string> cjt;
set<string> resposta;

void compare(string pai, string mae){
  string aux;
  if(pai[0] == 'O' && mae[0] == 'O'){ 
    aux.clear();
    ans.clear();
    aux.push_back('O');
    ans.push_back(aux); 
    return; 
  }
  if(pai[1] == '+' || pai[1] == '-') pai[1] = 'O';
  if(mae[1] == '+' || mae[1] == '-') mae[1] = 'O';
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      if(pai[i] == 'A' || mae[i] == 'A'){ 
	aux.clear();
	aux.push_back('A'); 
	ans.push_back(aux); 
      }
      if(pai[i] == 'B' || mae[i] == 'B'){ 
	aux.clear(); 
	aux.push_back('B'); 
	ans.push_back(aux); 
      }
      if((pai[i] == 'A' && mae[j] == 'B') || (mae[i] == 'A' && pai[j] == 'B')){ 
	aux.clear(); 
	aux.push_back('A'); 
	aux.push_back('B'); 
	ans.push_back(aux); 
      }
      if(pai[i] == 'O' && mae[i] == 'O'){ 
	aux.clear(); 
	aux.push_back('O'); 
	ans.push_back(aux); 
      }
    }
  }
}

void compara_pais(string pai, string mae, string filho, string wreplace, int who){
  if(who == 1){
    pai.clear(); ans.clear(); cjt.clear();
    pai.append(wreplace);
    compare(pai, mae);
    for(int i = 0; i < 3; i++){
      if(filho[i] == '+' || filho[i] == '-') filho[i] = '\0';
      if(pai[i] == '+' || pai[i] == '-') pai[i] = '\0';
    }
    for(vector<string>::iterator it = ans.begin(); it != ans.end(); ++it) cjt.insert(*it);
    for(set<string>::iterator it = cjt.begin(); it != cjt.end(); ++it)
      if(strcmp(filho.c_str(), (*it).c_str()) == 0){
	resposta.insert(pai);
      }
  }
  else{
    mae.clear(); ans.clear(); cjt.clear();
    mae.append(wreplace);
    compare(pai, mae);
    for(int i = 0; i < 3; i++){
      if(filho[i] == '+' || filho[i] == '-') filho[i] = '\0';
      if(mae[i] == '+' || mae[i] == '-') mae[i] = '\0';
    }
    for(vector<string>::iterator it = ans.begin(); it != ans.end(); ++it) cjt.insert(*it);
    for(set<string>::iterator it = cjt.begin(); it != cjt.end(); ++it)
      if(strcmp(filho.c_str(), (*it).c_str()) == 0){
	resposta.insert(mae);
      }
  }
}

int rhCompare(string pai, string mae){
  char rhp, rhm;
  for(int i = 0; i < 3; i++){
    if(pai[i] == '+' || pai[i] == '-') rhp = pai[i];
    if(mae[i] == '+' || mae[i] == '-') rhm = mae[i];
  }
  if(rhp == '+' || rhm == '+') return 1;
  return 2;
}

int rhCompare_pais(string pai, string mae){
  int rhp, rhm;
  for(int i = 0; i < 3; i++){
    if(pai[i] == '+' || pai[i] == '-') rhp = pai[i];
    if(mae[i] == '+' || mae[i] == '-') rhm = mae[i];
  }
  if(rhp == '-' && rhm == '+') return 3;
  return 1;
}

int main(void){
  char spai[5], smae[5], sfilho[5];
  string pai, mae, filho;
  string rhPai, rhMae, rhFilho;
  int rh;
  int count = 1;
  while(scanf(" %s %s %s", spai, smae, sfilho), spai[0] != 'E'){
    ans.clear(); cjt.clear(); pai.clear(); mae.clear(); filho.clear(); resposta.clear();
    rhPai.clear(); rhMae.clear(); rhFilho.clear();
    for(int i = 0; i < 3; i++){
      pai.push_back(spai[i]); mae.push_back(smae[i]); filho.push_back(sfilho[i]);
    }
    rhPai = pai; rhMae = mae; rhFilho = filho;
    if(spai[0] != '?' && smae[0] != '?'){
      compare(pai, mae);    
      for(vector<string>::iterator it = ans.begin(); it != ans.end(); it++) resposta.insert(*it);
      rh = rhCompare(rhPai, rhMae);
    }
    else{
      if(spai[0] == '?'){
	resposta.clear();
	compara_pais(pai, mae, filho, "A+", 1);
	compara_pais(pai, mae, filho, "B+", 1);
	compara_pais(pai, mae, filho, "O+", 1);
	compara_pais(pai, mae, filho, "AB+", 1);
	rh = rhCompare_pais(mae, rhFilho);
      }
      else{
	resposta.clear();
	compara_pais(pai, mae, filho, "A+", 0);
	compara_pais(pai, mae, filho, "B+", 0);
	compara_pais(pai, mae, filho, "O+", 0);
	compara_pais(pai, mae, filho, "AB+", 0);
	rh = rhCompare_pais(rhPai, rhFilho);
      }	
    }
    printf("Case %d: ", count++);
    if(rhPai[0] == '?'){
      if(resposta.size() == 0){ printf("IMPOSSIBLE %s %s\n", rhMae.c_str(), rhFilho.c_str()); continue; }
      if(resposta.size() != 1) printf("{");
      if(rh == 1)
	for(set<string>::iterator it = resposta.begin(); it != resposta.end(); ++it)
	  printf("%s%s+, %s-", it != resposta.begin() ? ", " : "", (*it).c_str(), (*it).c_str());
      else if(rh == 2)
	for(set<string>::iterator it = resposta.begin(); it != resposta.end(); ++it)
	  printf("%s%s-", it != resposta.begin() ? ", " : "", (*it).c_str());
      else
	for(set<string>::iterator it = resposta.begin(); it != resposta.end(); ++it)
	  printf("%s%s+", it != resposta.begin() ? ", " : "", (*it).c_str());
      printf("%s %s %s\n", (resposta.size() != 1 || rh == 1) ? "}" : "", rhMae.c_str(), rhFilho.c_str());
    }
    else if(rhMae[0] == '?'){
      printf("%s ", rhPai.c_str());
      if(resposta.size() == 0){ printf("IMPOSSIBLE %s\n", rhFilho.c_str()); continue; }
      if(resposta.size() != 1) printf("{");
      if(rh == 1)
	for(set<string>::iterator it = resposta.begin(); it != resposta.end(); ++it)
	  printf("%s%s+, %s-", it != resposta.begin() ? ", " : "", (*it).c_str(), (*it).c_str());
      else if(rh == 2)
	for(set<string>::iterator it = resposta.begin(); it != resposta.end(); ++it)
	  printf("%s%s-", it != resposta.begin() ? ", " : "", (*it).c_str());
      else
	for(set<string>::iterator it = resposta.begin(); it != resposta.end(); ++it)
	  printf("%s%s+", it != resposta.begin() ? ", " : "", (*it).c_str());
      printf("%s %s\n", (resposta.size() != 1 || rh == 1) ? "}" : "", rhFilho.c_str());
    }
    else{
      printf("%s %s ", rhPai.c_str(), rhMae.c_str());
      if(resposta.size() == 0){ printf("IMPOSSIBLE\n"); continue; }
      if(resposta.size() != 1 || rh == 1) printf("{");
      if(rh == 1)
	for(set<string>::iterator it = resposta.begin(); it != resposta.end(); ++it)
	  printf("%s%s+, %s-", it != resposta.begin() ? ", " : "", (*it).c_str(), (*it).c_str());
      else if(rh == 2)
	for(set<string>::iterator it = resposta.begin(); it != resposta.end(); ++it)
	  printf("%s%s-", it != resposta.begin() ? ", " : "", (*it).c_str());
      else
	for(set<string>::iterator it = resposta.begin(); it != resposta.end(); ++it)
	  printf("%s%s+", it != resposta.begin() ? ", " : "", (*it).c_str());
      printf("%s\n", (resposta.size() != 1 || rh == 1) ? "}" : "");
    }
  }
  return 0;
}
