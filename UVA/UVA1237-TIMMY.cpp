#include <cstdio>
#include <utility>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(void){
  vector< pair<int, int> > v;
  vector<string> s;
  string str;
  int tc, n, j, num, num1, num2, duplicate, found, first, i, q;
  string ans;
  scanf("%d", &tc);
  while(tc--){
    v.clear();
    s.clear();
    str.clear();
    ans.clear();
    i = 0;
    scanf("%d", &n);
    while(n--){
      cin >> str;
      s.push_back(str);
      scanf("%d %d", &num1, &num2);
      v.push_back(make_pair(num1, num2));
      i++;
    }
    scanf("%d", &q);
    while(q--){
      found = 0;
      duplicate = 0;
      first = 1;
      scanf("%d", &num);
      for(j = 0; j < i; j++){
	if(num >= v[j].first && num <= v[j].second){
	  found = 1;
	  if(first){
	    first = 0;
	    ans = s[j];
	  }
	  else{ duplicate = 1; break; }
	}
      }
      if(found && !duplicate) cout << ans << "\n";
      else printf("UNDETERMINED\n");
    }
    if(tc >= 1)
      printf("\n");
  }
  return 0;
}
