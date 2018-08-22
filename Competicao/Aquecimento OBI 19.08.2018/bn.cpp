#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1123456;

int main(void){
  int n;
  int v[MAXV];
  cin >> n;
  
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }

  for(int i = 1; i < n; i++){
    int sant = 0;
    if(i > 1) cout << " ";
    if(v[i] > v[i-1]) cout << v[i];
    else{
      if(sant > i) cout << v[sant];
      else{
	int found = 0;
	for(int j = i+1; j < n; j++){
	  if(v[j] > v[i-1]){ sant = j; found = 1; break; }
	}
	if(found) cout << v[sant];
	else cout << "*";
      }
    }
  }
  cout << " *\n";

  return 0;
}
