#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 100

int main(void){
  vector<char> v;
  char line[MAX];
  int stop = 0;
  while(!stop){
    scanf(" %s", line);
    if(line[0] == '#'){ stop++; continue; }
    if(next_permutation(line, line + strlen(line))) printf("%s", line);
    else printf("No Successor");
    printf("\n");
  }
  return 0;
}
