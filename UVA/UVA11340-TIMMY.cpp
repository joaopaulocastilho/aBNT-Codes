#include <cstdio>
#include <cstring>



#define MAX 312
#define MAXL 112345

int main(void){
  int vval[MAX], tc, cn, value, lines, ans;
  char line[MAXL], c;
  scanf("%d", &tc);
  while(tc--){
    memset(vval, 0, sizeof(vval));
    scanf("%d ", &cn);
    while(cn--){
      scanf("%c %d ", &c, &value);
      vval[(int)c] = value;
    }
    scanf("%d ", &lines);
    ans = 0;
    while(lines--){
      fgets(line, MAXL, stdin);
      int len = strlen(line);
      for(int i = 0; i < len; i++){
	if(line[i] >= 0 && line[i] <= 255)
	  if(vval[line[i]] != 0) ans += vval[line[i]];
      }
    }
    printf("%.2lf$\n", ((double)ans)/100);
  }
  return 0;
}
