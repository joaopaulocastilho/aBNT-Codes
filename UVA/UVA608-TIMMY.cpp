#include <cstdio>
#include <cstring>

#define SUSPEITO 1
#define SALVO 2
#define FALSO 3
#define LEVE 1
#define PESADO 2

int v[12], pe[12], pd[12], ans;
char right[4][10], left[4][10], result[4][10];

int main(void){
  int tc, peso, found, len, suml, sumr, ans, fake, j;
  scanf("%d", &tc);
  while(tc--){
    for(int i = 0; i < 3; i++)
      scanf("%s %s %s", left[i], right[i], result[i]);
    found = 0;
    for(int i = 0; i < 12 && !found; i++){
      memset(v, 0, sizeof(v));
      v[i] = 1;
      for(j = 0; j < 3; j++){
	suml = sumr = 0;
	len = strlen(left[j]);
	for(int k = 0; k < len; k++) suml += v[left[j][k]-'A'];
	for(int k = 0; k < len; k++) sumr += v[right[j][k]-'A'];
	if(result[j][0] == 'e') ans = 0;
	else if(result[j][0] == 'u') ans = -1;
	else ans = 1;
	if(suml - sumr == -ans) continue;
	else{ break;  }
      }
      if(j == 3){ found = 1; fake = i; }
    }
    for(int i = 0; i < 12 && !found; i++){
      memset(v, 0, sizeof(v));
      v[i] = -1;
      for(j = 0; j < 3; j++){
	suml = sumr = 0;
	len = strlen(left[j]);
	for(int k = 0; k < len; k++) suml += v[left[j][k]-'A'];
	for(int k = 0; k < len; k++) sumr += v[right[j][k]-'A'];
	if(result[j][0] == 'e') ans = 0;
	else if(result[j][0] == 'u') ans = -1;
	else ans = 1;
	if(suml - sumr == -ans) continue;
	else{ break;  }
      }
      if(j == 3){ found = 1; fake = i; }
    }
    for(int i = 0; i < 12; i++)
      if(v[i] == 1 || v[i] == -1) printf("%c is the counterfeit coin and it is %s.\n", fake+'A', v[fake] == 1 ? "heavy" : "light");
  }
  return 0;
}
