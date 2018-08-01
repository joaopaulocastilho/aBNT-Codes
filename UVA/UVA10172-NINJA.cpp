#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

int main(void){
  int i, t, n, s, q, done, qtd, num, pos, ans;

  scanf("%d", &t);
  while(t--){
    vector <queue<int> > stations;
    stack <int> st;
    scanf("%d %d %d", &n, &s, &q);
    for(i = 0; i < n; i++){
      scanf("%d", &qtd);
      while(qtd--){
	scanf("%d", &num);
	num--;
	stations.push_back(queue<int>());
	stations[i].push(num);
      }
    }
    //printf("Leitura de boa\n");
    for(ans = pos = 0; ; pos = pos == n-1 ? 0 : pos + 1, ans += 2){
      //printf("Estação %d, tempo %d\n", pos, ans);
      while(!st.empty()){
	if(st.top() == pos) {ans++; st.pop(); }
	else if(stations[pos].size() < q){
	  //printf("Enfileirou %d\n", st.top());
	  stations[pos].push(st.top());
	  st.pop(); ans++;
	}
	else break;
      }
      while(!stations[pos].empty() && st.size() < s){
	//printf("Carregou %d\n", stations[pos].front());
	st.push(stations[pos].front());
	stations[pos].pop();
	ans++;
      }
      for(done = 1, i = 0; i < n; i++) done &= stations[i].empty();
      done &= st.empty();
      if(done) break;
    }
    printf("%d\n", ans);
  }

  return 0;
}
