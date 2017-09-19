#include <stdio.h>
#include <string.h>
#define MAX 112345
#define DEBP

char num_dec[MAX];
char bases[MAX];
int tamc;

int trans_int(){
  int num=0, i, mult = 1;
  for(i=strlen(num_dec)-1; i>=0; i--){
    num += (num_dec[i]-'0') * mult;
    mult *= 10; 
  }
  return num;
}

int letra(int num){
  int i;
  for(i=10; i<16; i++){
    if(num == i) return i-10+'A';
  }
  return 0;
}

void conv(int b, int n){
  int aux;
  tamc=0;
  memset(bases, 0, sizeof(bases));
  while(n/b >= 1){
    aux = n/b;
    if(n%b > 9) bases[tamc++] = letra(n%b);
    else bases[tamc++] = n%b;
    n /= b;
  }
  if(aux > 9) bases[tamc++] = letra(aux);
  else bases[tamc++] = aux;
}

int capicua(){
  int i;
  char troca[MAX], cont=0;
  for(i=0; i<tamc; i++){
    troca[i] = bases[tamc-1-i];
  }
  for(i=0; i<tamc; i++){
    if(troca[i] == bases[i]) cont++;
  }

  if(cont == tamc) return 1;
  return 0;
}

int main(void){
  int t, num, i, flag, cont;
  scanf("%d", &t);
  while(t--){
    memset(num_dec, 0, sizeof(num_dec));
    scanf("%s", num_dec);
    num = trans_int();
    cont = 0;
    flag = 0;
    for(i=2; i<=16; i++){
      conv(i, num);
      if(capicua()){
	if(flag) printf(" ");
	else flag = 1;
	printf("%d", i);
	cont++;
      }
    }
    if(cont == 0) printf("-1");
    printf("\n");
  }
  return 0;
}
