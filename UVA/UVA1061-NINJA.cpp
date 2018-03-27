#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <algorithm>
#include <string>

#define MAX 112

using namespace std;

map <string, string> combType;
map <string, string> typeComb;

int main(void){
  int i, j, first, end, caso = 1;
  char pai1[MAX], pai2[MAX], npai[MAX], filho[MAX], rh1, rh2, rhs[3];
  
  combType["AA"] = "A";
  combType["AB"] = "AB";
  combType["AO"] = "A";
  combType["BB"] = "B";
  combType["BO"] = "B";
  combType["OO"] = "O";

  typeComb["A"] = "AO";
  typeComb["AB"] = "AB";
  typeComb["B"] = "BO";
  typeComb["O"] = "OO";

  while(scanf("%s %s %s ", pai1, pai2, filho), pai1[0] != 'E'){
    if(pai1[0] == '?'){ rh1 = pai2[strlen(pai2)-1]; rh2 = filho[strlen(filho)-1]; }
    else if(pai2[0] == '?'){ rh1 = pai1[strlen(pai1)-1]; rh2 = filho[strlen(filho)-1]; }
    else { rh1 = pai1[strlen(pai1)-1]; rh2 = pai2[strlen(pai2)-1]; };
    if(filho[0] == '?')
      if(rh1 == '+' || rh2 == '+') strcpy(rhs, "+-");
      else strcpy(rhs, "-");
    else if(rh1 == '-' && rh2 == '+') strcpy(rhs, "+");
    else strcpy(rhs, "+-");
    //printf("%c %c\n", rh1, rh2);
    if(pai1[0] != '?') pai1[strlen(pai1)-1] = 0;
    if(pai2[0] != '?') pai2[strlen(pai2)-1] = 0;
    if(filho[0] != '?') filho[strlen(filho)-1] = 0;
    //printf("%s %s %s\n", pai1, pai2, filho);
    if(filho[0] == '?'){
      set <char> alelos1;
      set <char> alelos2;
      set <string> combs;
      set <string> bTypes;
      for(map<string, string>::iterator it = typeComb.begin(); it != typeComb.end(); it++){
	//printf("%s %s %s\n", pai1, pai2, it->first.c_str());
	if(!strcmp(pai1, (it->first).c_str()))
	  for(i = 0; i < (it->second).length(); i++) alelos1.insert((it->second)[i]);
	if(!strcmp(pai2, (it->first).c_str()))
	  for(i = 0; i < (it->second).length(); i++) alelos2.insert((it->second)[i]);
      }
      for(set<char>::iterator it = alelos1.begin(); it != alelos1.end(); it++){
	for(set<char>::iterator it2 = alelos2.begin(); it2 != alelos2.end(); it2++){
	  //printf("%c %c\n", *it, *it2);
	  char novaComb[3];
	  novaComb[0] = *it < *it2 ? *it : *it2;
	  novaComb[1] = *it > *it2 ? *it : *it2;
	  novaComb[2] = 0;
	  //printf("%s\n", novaComb);
	  combs.insert(novaComb);
	}
      }
      for(set<string>::iterator it = combs.begin(); it != combs.end(); it++)
	for(map<string,string>::iterator it2 = combType.begin(); it2 != combType.end(); it2++){
	  if(!strcmp(it->c_str(), (it2->first).c_str())) bTypes.insert(it2->second);
	}
      //printf("%s\n", rhs);
      printf("Case %d: %s%c %s%c ", caso++, pai1, rh1, pai2, rh2);
      end = strlen(rhs);
      if(bTypes.size() * end > 1) printf("{");
      first = 1;
      for(set<string>::iterator it = bTypes.begin(); it != bTypes.end(); it++){
	//printf("\nOLHA %s\n", (*it).c_str());
	for(i = 0; i < end; i++){
	  if(first) first = 0;
	  else printf(", ");
	  printf("%s%c", (*it).c_str(), rhs[i]);
	}
      }
      if(bTypes.size() * end > 1) printf("}");
      printf("\n");
    }
    else{
      set<string> bTypes;
      if(pai1[0] == '?') strcpy(npai, pai2);
      else strcpy(npai, pai1);
      //printf("%s\n", npai);
      for(map<string,string>::iterator it = typeComb.begin(); it != typeComb.end(); it++){
	string combPai = typeComb[npai];
	for(i = 0; i < combPai.length(); i++)
	  for(j = 0; j < (it->second).length(); j++){
	    //printf("Combinando %c com %c\n", combPai[i], it->second[j]);
	    char novaComb[3];
	    novaComb[0] = combPai[i] < it->second[j] ? combPai[i] : it->second[j];
	    novaComb[1] = combPai[i] > it->second[j] ? combPai[i] : it->second[j];
	    novaComb[2] = 0;
	    if(!strcmp(combType[novaComb].c_str(), filho)) bTypes.insert(it->first);
	  }
      }
      first = 1;
      printf("Case %d: ", caso++);
      if(pai1[0] != '?') printf("%s%c ", pai1, rh1);
      end = strlen(rhs);
      if(bTypes.size() * end > 1) printf("{");
      if(bTypes.size() == 0) printf("IMPOSSIBLE ");
      else
	for(set<string>::iterator it = bTypes.begin(); it != bTypes.end(); it++){
	  for(i = 0; i < end; i++){
	    if(first) first = 0;
	    else printf(", ");
	    printf("%s%c", it->c_str(), rhs[i]);
	  }
	}
      if(bTypes.size() * end > 1) printf("} ");
      if(pai2[0] != '?') printf("%s%c ", pai2, rh1);
      printf("%s%c\n", filho, rh2);
    }
  }
  return 0;
}
