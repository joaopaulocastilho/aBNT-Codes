#include <cstdio>
#include <utility>
#include <cstring>

using namespace std;

#define MAX 112

int main(void){
  int count, i, tc, j, power, len, t, hack, health;
  char command[MAX];
  scanf("%d", &tc);
  for(t = 1; t <= tc; t++){
    hack = 0;
    printf("Case #%d: ", t);
    scanf("%d %s", &health, command);
    len = strlen(command);
    for(i = count = 0; i < len; i++) if(command[i] == 'S') count++;
    if(count > health){ printf("IMPOSSIBLE\n"); continue; }
    for(j = count = 0, power = 1; j < len; j++){
      if(command[j] == 'S') count += power;
      if(command[j] == 'C') power *= 2;
    }
    if(count <= health)
      printf("%d\n", hack);
    else{
      for(i = len-1; i >= 1; i--){
	if(command[i-1] == 'C' && command[i] == 'S'){
	  swap(command[i-1], command[i]);
	  hack++;
	  for(j = count = 0, power = 1; j < len; j++){
	    if(command[j] == 'S') count += power;
	    if(command[j] == 'C') power *= 2;
	  }
	  if(count > health)
	    i = len;
	  else break;
	}
	//for(int k = 0; k < len; k++) printf("%c", command[k]); printf("\n");
      }
      if(i == 0) printf("IMPOSSIBLE\n");
      else printf("%d\n", hack);
    }
  }

  return 0;
}
