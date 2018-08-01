#include <stdio.h>
#include <string.h>

#define MAX 

char binn[50], bina[50], binb[50];

void toBin(int n){
  int i, j;
  long long int exp;
  
  for(exp = 1, i = 0; n >= exp; i++, exp *= 2);
  //printf("%d %d\n", exp, i-1);
  for(exp /= 2, binn[i] = j = 0; j < i; j++, exp /= 2){
    //printf("|- %d %d\n", j, exp);
    if(exp <= n){
      binn[j] = '1';
      n -= exp;
    }
    else binn[j] = '0';
  }
  //printf("%s\n", binn);
}

int toDec(char bin[]){
  int i, end, ans, exp;

  end = strlen(bin);
  for(ans = 0, exp = 1, i = end-1; i >= 0; i--, exp *= 2)
    ans += exp * (bin[i] - '0');
  return ans;
}

int main(void){
  int i, n, end, count ;
  
  while(scanf("%d", &n), n){
    toBin(n);
    end = strlen(binn);
    for(i = end-1, count = 1, bina[end] = binb[end] = 0; i >= 0; i--){
      bina[i] = binb[i] = '0';
      if(binn[i] == '1' && count % 2) { bina[i] = '1'; count++; }
      else if(binn[i] == '1' && count % 2 == 0) { binb[i] = '1'; count++; }
    }
    //printf("%s\n%s\n%s\n", binn, bina, binb);
    printf("%d %d\n", toDec(bina), toDec(binb));
  }
  
  return 0;
}
