#include <stdio.h>
#include <map>
#include <string>
#include <string.h>

using namespace std;

#define MAX 112

int main(void){
  int t, ttl, first = 1;
  char line[MAX];
  
  scanf("%d ", &t);
  //getchar();
  while(t--){
    ttl = 0;
    map<string, int> trees;
    while(fgets(line, MAX, stdin) && line[0] != '\n'){
      ttl++;
      line[strlen(line)-1] = 0;
      if(trees.find(line) == trees.end()) trees[line] = 1;
      else trees[line]++;
    }
    if(first) first = 0;
    else printf("\n");
    for(map<string, int>::iterator it = trees.begin(); it != trees.end(); it++)
      printf("%s %.4lf\n", it->first.c_str(), ((double)it->second*100)/ttl);
  }

  return 0;
}
