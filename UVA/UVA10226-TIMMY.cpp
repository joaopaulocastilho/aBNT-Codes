#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

#define MAX 40

typedef struct IntAndString{
  string str;
  int num;
} is;

bool op(is i, is j){ return i.str < j.str; }

int main(void){
  map<string, int> m;
  char cstr[MAX];
  string str;
  int tc, count, len;
  vector<is> mp;
  is idx;
  if(scanf("%d ", &tc));
  while(tc--){
    mp.clear();
    m.clear();
    count = 0;
    while(fgets(cstr, MAX, stdin) && cstr[0] != '\n'){
      count++;
      str.clear();
      len = strlen(cstr);
      cstr[len-1] = '\0';
      str.append(cstr);
      m[str]++;
    }
    for(map<string, int>::const_iterator it = m.begin(); it != m.end(); ++it){
      idx.str = it->first; idx.num = it->second;
      mp.push_back(idx);
    }
    sort(mp.begin(), mp.end(), op);
    for(vector<is>::iterator it = mp.begin(); it != mp.end(); ++it){
      len = (it->str).size();
      cout << it->str;
      printf(" %.4lf\n", (((double)it->num)/(double)count)*100);
    }
    if(tc > 0) printf("\n");
  }
  return 0;
}
