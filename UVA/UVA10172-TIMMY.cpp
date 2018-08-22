#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;


int main(void){
  vector<queue<int> >vst;
  queue<int> qw;
  stack<int> cargo;
  queue<int> aux;
  int qtd, n, s, q, num, tc, count, size, min, ccount;
  cin >> tc;
  while(tc--){
    vst.clear();
    while(qw.size() > 0) qw.pop();
    while(cargo.size() > 0) cargo.pop();
    cin >> n >> s >> q;
    size = 0;
    for(int i = 0; i < n; i++){
      cin >> qtd;
      size+= qtd;
      while(!qw.empty()) qw.pop();
      while(qtd--){ cin >> num;  qw.push(num); }
      vst.push_back(qw);
    }
    min = 0;
    while(size > 0){
      count = 1;
      for(vector<queue<int> >::iterator it = vst.begin(); it != vst.end() && size > 0; ++it, ++count, min+= 2){
	while((int)cargo.size() > 0 && cargo.top() == count){ cargo.pop(); size--; min++; }
	while((int)cargo.size() > 0 && (int)it->size() < q){
	  it->push(cargo.top()); cargo.pop(); min++;
	  while((int)cargo.size() > 0 && cargo.top() == count){ cargo.pop(); size--; min++; }
	}
	while((int)it->size() > 0 && (int)cargo.size() < s){ cargo.push(it->front()); it->pop(); min++; }
	ccount = 1;
	/*
	for(vector<queue<int> >::iterator it2 = vst.begin(); it2 != vst.end(); ++it2){
	  cout << ccount++ << " - ";
	  while(!it2->empty()){ cout << it2->front() << " "; aux.push(it2->front()); it2->pop(); }
	  while(!aux.empty()){ it2->push(aux.front()); aux.pop(); }
	  cout << "\n";
	}
	cout << "--\n";
	*/
	if(size == 0) break;
      }
    }
    cout << min << "\n";
    
  }
  return 0;
}
