#include <iostream>
#include <set>

using namespace std;

#define MAX 1123

int main(void){
  int matrix[MAX][MAX];
  set<int> s;
  int n; cin >> n;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      int num; cin >> num;
      matrix[i][j] = num;
    }
  }
  for(int i = 0; i < 2*n; i++){
    int x, y; cin >> x >> y;
    s.insert(matrix[x][y]);
  }
  cout << s.size() << endl;
  return 0;
}
