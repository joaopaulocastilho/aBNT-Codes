#include <bits/stdc++.h>

const int MAX = 1123;

int main(void){
  int i, j, n, stud[MAX], vis[MAX];

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &stud[i]);
  for(i = 0; i < n; i++){
    memset(vis, 0, sizeof(vis));
    for(j = i; !vis[j]; j = stud[j]-1) vis[j] = 1;
    printf("%s%d", i ? " " : "", j+1); 
  }
  printf("\n");
  
  return 0;
}
