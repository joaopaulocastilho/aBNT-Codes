#include <stdio.h>
#include <list>
#include <string>
#include <string.h>

using namespace std;

#define MAX 112345

int main(void){
  int i, j, end, flag, count;
  char line[MAX];
  list<char>::iterator it;

  while(scanf("%s ", line) != EOF){
    list <char> l;
    string s = string();
    end = strlen(line);
    for(count = flag = i = 0; i < end; i++){
      if(line[i] == '['){
	flag = 1;
	it = l.begin();
      }
      else if(line[i] == ']') flag = 0;
      else if(!flag) l.push_back(line[i]);
      else l.insert(it, line[i]);
    }
    for(it = l.begin(); it != l.end(); it++) printf("%c", *it);
    printf("\n");
  }

  return 0;
}
