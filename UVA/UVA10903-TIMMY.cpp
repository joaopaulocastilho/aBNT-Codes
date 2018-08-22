#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
#define MAX 10050
using namespace std;

int arr[MAX];
int leave[MAX];

int main() {
  int tc, first = 1; 
  int n,t,m;
  cin >> tc;
  while (tc--) {
    if (!first) cout << endl;
    else first = 0;
    memset(arr,0,sizeof(arr));
    memset(leave,0,sizeof(leave));
    cin >> n >> t >> m;
    queue<int> q[2];
    for(int i=0;i<m;i++){
      int tm; string loc;
      cin >> tm >> loc;
      if (loc == "left") q[0].push(i);
      else q[1].push(i);
      arr[i] = tm;
    }
    int currTime = 0;
    int currSide = 0;
    while (!q[0].empty() || !q[1].empty()) {
      int nextTime = 0;
      if (q[0].empty())
	nextTime = arr[q[1].front()];
      else if (q[1].empty())
 	nextTime = arr[q[0].front()];
      else
	nextTime = min(arr[q[0].front()],arr[q[1].front()]);
      currTime = max(currTime , nextTime);
      int count = 0;
      while ((!q[currSide].empty()) && (currTime >= arr[q[currSide].front()]) && (count < n)) {
	leave[q[currSide].front()] = currTime + t;
	q[currSide].pop(); count++;
      }
      currTime += t; // travel to the other side
      currSide ^= 1; // toggle side between 0 and 1
    }
    for(int i=0; i<m; i++){
      cout << leave[i] << endl;
    }
  }
  return 0;
}
