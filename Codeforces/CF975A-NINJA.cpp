#include <stdio.h>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 1123

int main(void){
  int n, i;
  char str[MAX];
  set<string> roots;

  scanf("%d", &n);
  while(n--){
    scanf("%s", str);
    string word = string(str);
    sort(word.begin(), word.end());
    for(i = 1; i < (int)word.length(); i++)
      if(word[i] == word[i-1]) word.erase(word.begin() + i--);
    //printf("%s\n", word.c_str());
    if(roots.find(word) == roots.end()) roots.insert(word);
  }
  printf("%d\n", (int)roots.size());
  
  return 0;
}
