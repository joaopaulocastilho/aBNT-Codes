#include <cstdio>
#include <cstring>

#define MAX 112345

typedef struct{
  int left;
  int right;
} node_t;

int main(void){
  node_t node[MAX];
  int s, b, lossl, lossr;
  while(scanf("%d %d", &s, &b), s != 0){
    for(int i = 1; i <= s; i++){ node[i].left = i-1; node[i].right = i+1; }
    node[s].right = 0;
    while(b--){
      scanf("%d %d", &lossl, &lossr);
      if(node[lossl].left)
	printf("%d ", node[lossl].left);
      else printf("* ");
      if(node[lossr].right)
	printf("%d\n", node[lossr].right);
      else printf("*\n");
      node[node[lossl].left].right = node[lossr].right;
      node[node[lossr].right].left = node[lossl].left;
    }
    printf("-\n");
  }
  return 0;
}
