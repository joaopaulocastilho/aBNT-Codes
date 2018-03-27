#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define MAX 1123456

int cmp(const void *a, const void *b){
  return *(char*)a - *(char*)b;
}

int main(void){
  int i, j, n, end, first = 1;
  char line[MAX], line2[MAX];
  string str;

  map< string, string> anas;
  set <string> words;
  
  scanf("%d\n", &n);

  while(n--){
    words.clear(); anas.clear();
    while(fgets(line, MAX, stdin) && line[0] != '\n'){
      str.clear();
      end = strlen(line);
      line[end-1] = 0;
      strcpy(line2, line);
      qsort(line, end-1, sizeof(char), &cmp);
      for(j = i = 0; i < end; i++)
	if(line[i] != ' ') str.push_back(line[i]);
      //str.sort(str.begin(), str.end());
      anas[line2] = str;
      words.insert(line2);
      //printf("%s -> %s\n", line2, anas[line2].c_str());
    }
    //printf("%d\n", words.size());
    if(first) first = 0;
    else printf("\n");
    for(set<string>::iterator it = words.begin(); it != words.end(); it++){
      set<string>::iterator ot = it;
      for(++ot; ot != words.end(); ot++){
	if(!strcmp(anas[(*it).c_str()].c_str(), anas[(*ot).c_str()].c_str()))
	   printf("%s = %s\n", (*it).c_str(), (*ot).c_str());
      }
    }
  }
  return 0;
}
