#include <cstdio>
#include <cstring>
#include <stdlib.h>

#define MAX 30

int main(void){
  int check1[MAX], check2[MAX];
  int count, tc;
  char c;
  scanf("%d", &tc);
  getchar();
  while(tc--){
    count = 0;
    memset(check1, 0, sizeof(check1));
    memset(check2, 0, sizeof(check2));
    while((c = getchar()) != '\n') check1[(c - 'a')]++;
    while((c = getchar()) != '\n' && c != EOF) check2[(c - 'a')]++;
    for(int i = 0; i < MAX; i++)
      count += abs(check1[i] - check2[i]);
    printf("%d\n", count);
  }
  return 0;
}
