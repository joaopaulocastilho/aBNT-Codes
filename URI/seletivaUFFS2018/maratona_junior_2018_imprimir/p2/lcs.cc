#include <iostream>
#include <vector>
using namespace std;


vector<vector<int> > cache;

int lcs(const string & a, const string & b, const int pa, const int pb) {
  int & r = cache[pa][pb];
  if(r >= 0) return r;
  if(pa >= a.size()) return 0;
  if(pb >= b.size()) return 0;
  if(a[pa]== b[pb]) return r = 1 + lcs(a, b, pa+1, pb+1);

  int x = lcs(a, b, pa+1, pb);
  int y = lcs(a, b, pa, pb+1);
  return r = max(x, y);
}


int main() {
  string a, b;
  cin >> a >> b;
  cache.assign(a.size()+1, vector<int>(b.size()+1, -1));
  cout << lcs(a, b, 0, 0) << '\n';
  return 0;
}
