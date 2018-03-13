#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define MAX 1123
#define INF 112345

map<int, int> letter;
map<int, int> vletter;
char s[MAX];
set< vector<int> > conj;

/*
void order(){
  int len = strlen(s), pos, minor, swap, tmp;
  for(int i = 0; i < len; i++){
    minor = letter[s[i]];
    swap = 0;
    for(int j = i+1; j < len; j++){
      if(letter[s[j]] < minor){
	minor = letter[s[j]];
	pos = j;
	swap = 1;
      }
    }
    if(swap){
      tmp = s[i];
      s[i] = s[pos];
      s[pos] = tmp;
    }
  }
}
*/

void permute(vector<int> str, int l, int r){
  int i;
  if(l == r){
    conj.insert(str);
  }
  else{
    for(i = l; i <= r; i++){
      swap(str[l], str[i]);
      if(conj.find(str) != conj.end())
	continue;
      permute(str, l+1, r);
      swap(str[l], str[i]);
    }
  }
}


int main(void){
  int tc, len;
  vector<int> str;
  scanf("%d", &tc);
  for(int i = 0, j = 0; i < 52; i+=2, j++){
    letter['A'+j] = i;
    letter['a'+j] = i+1;
    vletter[i] = 'A' + j;
    vletter[i+1] = 'a' + j;
  }
  while(tc--){
    conj.clear();
    str.clear();
    scanf(" %s", s);
    len = strlen(s);
    for(int i = 0; i < len; i++){
      str.push_back(letter[s[i]]);
    }
    permute(str, 0, len-1);
    for(set< vector<int> >::iterator it = conj.begin(); it != conj.end(); ++it){
      for(int i = 0; i < (*it).size(); ++i)
	printf("%c", vletter[(*it)[i]]);
      printf("\n");
    }
  }
  return 0;
}
