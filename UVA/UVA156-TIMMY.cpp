#include <cstdio>
#include <set>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

#define MAX 1123

int main(void){
  set<string> cjt;
  char word[MAX];
  int matrix[MAX][27], palavra[27];
  int count = 0, comp[27], anacount;
  memset(matrix, 0, sizeof(matrix));
  while(scanf("%s", word), word[0] != '#'){
    cjt.insert(word);
    int len = strlen(word);
    for(int i = 0; i < len; i++){
      if(word[i] >= 'A' && word[i] <= 'Z') word[i] += 32;
      matrix[count][word[i]-'a']++;
    }
    count++;
  }
  for(set<string>::iterator it = cjt.begin(); it != cjt.end(); ++it){
    memset(word, 0, sizeof(word));
    memset(palavra, 0, sizeof(palavra));
    anacount = 0;
    for(int i = 0, j = 0; i < (*it).length(); i++){
      word[j] = (*it)[i];
      palavra[word[j] - 'a' + (word[j] >= 'A' && word[j] <= 'Z' ? 32 : 0)]++;
      j++;
    }
    for(int i = 0; i < count; i++){
      int achou = 0;
      for(int j = 0; j < 26; j++)
	if(matrix[i][j] != palavra[j]) achou = 1;
      if(!achou) anacount++;
    }
    if(anacount < 2)
      printf("%s\n", word);
  }
  return 0;
}
