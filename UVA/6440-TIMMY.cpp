#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112345;

typedef struct{
  int t0, st0, r;
} patient_t;

int main(void){
  int t;
  cin >> t;
  for(int caso = 1; caso <= t; caso++){
    int n;
    string str;
    vector<patient_t> patients;
    cin >> n;
    cout << "Case #" << caso << ":\n";
    for(int i = 0; i < n; i++){
      cin >> str;
      if(str == "P"){
	patient_t p;
	cin >> p.t0 >> p.st0 >> p.r;
	patients.push_back(p);
      }
      else{
	int k;
	cin >> k;
	patient_t mp;
	int maior = -1, idx;
	for(int j = 0; j < (int)patients.size(); j++){
	  int st = patients[j].st0 + patients[j].r * ( k - patients[j].t0);
	  if(st > maior){
	    maior = st;
	    mp = patients[j];
	    idx = j;
	  }
	  else if(st == maior && patients[j].r > mp.r){
	    mp = patients[j];
	    idx = j;
	  }
	}
	cout << maior<< " " << mp.r << "\n";
	patients.erase(patients.begin()+idx);
      }
    }
  }

  return 0;
}
