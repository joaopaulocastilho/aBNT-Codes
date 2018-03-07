#include <stdio.h>
#include <string.h>
#include <set>
#include <string>

#define MAX 98
#define MAX2 1123

using namespace std;

int main(void){
  int i, j, end, k = 0, wcount = 0, ana, anana, wletters[30], letters[MAX2][30];
  set <string> words;
  char str[MAX];
  memset(letters, 0, sizeof(letters));
  while(scanf("%s ", str)){
    if(strcmp(str, "#") == 0) break;
    wcount++;
    words.insert(str);
    end = strlen(str);
    for(i = 0; i < end; i++){
      if(str[i] >= 'A' && str[i] <= 'Z') str[i] += ' ';
      letters[k][str[i] - 'a']++;
    }
    k++;
  }
  for(set <string>::iterator it = words.begin(); it != words.end(); it++){
    memset(wletters, 0, sizeof(wletters));
    for(j = i = 0; i < (*it).length(); i++, j++){
      str[j] = (*it)[i];
      if(str[j] >= 'A' && str[j] <= 'Z') str[j] += ' ';
      wletters[str[j] - 'a']++;
    }
    str[j] = 0;
    for(anana = 2, i = 0; i < wcount; i++){
      for(ana = 1, j = 0; j < 26; j++){
	if(letters[i][j] != wletters[j]) ana = 0;
      }
      if(ana) anana--;
    }
    if(anana > 0) printf("%s\n", (*it).c_str());
  }
  return 0;
}
