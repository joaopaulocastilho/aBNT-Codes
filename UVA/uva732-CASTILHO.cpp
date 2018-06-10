#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

#define MAX 112345
#define PUSH 1
#define POP 0

char stro[MAX], stra[MAX];

void bt(stack<char>&st, int p, int io, int ia, int l, int resp[]) {
  int i, aux;
  if (p == l * 2) {
    for (i = 0; i < l * 2; i++) {
      if (i) printf(" ");
      printf("%c", resp[i]  == PUSH ? 'i' : 'o');
    }
    printf("\n");
    return;
  }
  if (io < l) {
    st.push(stro[io]); resp[p] = PUSH;
    bt(st, p + 1, io + 1, ia, l, resp);
    st.pop();
  }
  if (ia < l && !st.empty() && st.top() == stra[ia]) {
    aux = st.top(); st.pop();
    resp[p] = POP;
    bt(st, p + 1, io, ia + 1, l, resp);
    st.push(aux);
  }}

int main(void) {
  int tamo, tama, resp[MAX];
  while (scanf("%s %s ", stro, stra) != EOF) {
    stack<char>st;
    tamo = strlen(stro); tama = strlen(stra);
    printf("[\n");
    if (tamo == tama) bt(st, 0, 0, 0, tamo, resp);
    printf("]\n");
  }
  return 0;
}
