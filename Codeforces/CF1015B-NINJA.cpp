#include <bits/stdc++.h>

using namespace std;

const int MAX = 112345;

int cmp(const void *a, const void *b){ return *(char*)a - *(char*)b; }

int main(void){
  int i, j, n, ans = 0;
  char s[MAX], t[MAX], str1[MAX], str2[MAX];
  vector<int> moves;
  
  scanf("%d", &n);
  scanf(" %s", s);
  scanf(" %s", t);
  strcpy(str1, s); strcpy(str2, t);
  qsort(str1, strlen(str1), sizeof(char), &cmp);
  qsort(str2, strlen(str2), sizeof(char), &cmp);

  if(strcmp(str1, str2)) ans = -1;
  if(ans != -1){
    for(i = strlen(s)-1; i > 0; i--){
      if(s[i] == t[i]) continue;
      for(j = i-1; s[j] != t[i]; j--);
      while(i != j){
	swap(s[j], s[j+1]);
	moves.push_back(j+1);
	j++; ans++;
      }
    }
  }
  printf("%d\n", ans);
  for(i = 0; i < moves.size(); i++)
    printf("%s%d", i ? " " : "", moves[i]);
  printf("\n");
  return 0;
}
