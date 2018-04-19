#include <cstdio>
#include <cstring>

#define MAX 1123

int main(void){
  int n, m, v[MAX], resto[MAX], complete, point, num;
  scanf("%d %d", &n, &m);
  memset(v, 0, sizeof(v));
  memset(resto, 0, sizeof(resto));
  point = 0;
  while(m--){
    scanf("%d", &num);
    num--;
    if(v[num] == 1) resto[num]++;
    else v[num] = 1;
    complete = 1;
    for(int i = 0; i < n; i++)
      if(v[i] == 0){ complete = 0; break; }
    if(complete){
      memset(v, 0, sizeof(v));
      for(int i = 0; i < n; i++) if(resto[i] != 0){ v[i]++; resto[i]--; }
      point++;
    }
    //for(int i = 0; i < n; i++) printf("%d ", v[i]); printf("\n");
    //for(int i = 0; i < n; i++) printf("%d ", resto[i]); printf("\n");
    //printf("\n");
  }
  printf("%d\n", point);
  return 0;
}
