#include <stdio.h>
#include <stack>

using namespace std;

#define MAX 112345

int main(void) {
  int i, n, t[MAX], tp;
  while (scanf("%d", &n), n) {
    while (scanf("%d", &t[0]), t[0]) {
      stack<int> st;
      for (i = 1; i < n; i++) scanf("%d", &t[i]);
      for (tp = 1, i = 0; tp <= n; tp++) {
        st.push(tp);
        //printf("%d\n", st.top());
        while (i < n && !st.empty() && st.top() == t[i]) { i++; st.pop(); }
      }
      printf("%s\n", st.empty() ? "Yes" : "No");
    }
    printf("\n");
  }
  return 0;
}
