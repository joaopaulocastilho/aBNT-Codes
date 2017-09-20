#include <stdio.h>
#include <string.h>

#define MAX 112

typedef unsigned long long ull;

char cpf[20];

int compara(char i){
  if(i-'0' >= 0 && i-'0'<=9) return 1;
  return 0;
}

int pega_cpf(char s[MAX]){
  int i, cont=0;
  for(i=0; cont<11; i++){
    if(compara(s[i])) cpf[cont++]=s[i];
  }
  cpf[cont] = '\0';
  return i;
}

ull pega_n(int ini, char s[MAX], int &pos_p){
  char n[MAX];
  int i, cont=0;
  ull num=0, mult=1;
  for(i=ini; i<strlen(s) && s[i]!='.'; i++){
    if(compara(s[i])) n[cont++]=s[i];
  }
  if(i<strlen(s)) pos_p = i;
  else pos_p = -1;
  for(i=cont-1; i>=0; i--){
    num += ((n[i]-'0')*mult);
    mult*=10;
  }
  return num;
}

double pega_d(int ini, char s[MAX]){
  int i, cont=0;
  char n[MAX];
  double num = 0.0, mult = 0.1;
  if(ini == -1) return 0.0;
  for(i=ini; i<strlen(s); i++)
    if(compara(s[i])) n[cont++]=s[i];
  for(i=0; i<cont && i<2; i++){
    num += (n[i]-'0')*mult;
    mult*=0.1;
  }
  return num;
}

int main(void){
  int pos_cpf, pos_p, dec;
  ull n1, n2;
  double d1, d2;
  char s1[MAX], s2[MAX];
  memset(s1, 0, sizeof(s1));
  memset(s2, 0, sizeof(s2));
  fgets(s1, sizeof(s1), stdin);
  fgets(s2, sizeof(s2), stdin);
  pos_cpf = pega_cpf(s1);
  n1 = pega_n(pos_cpf, s1, pos_p);
  d1 = pega_d(pos_p, s1);
  n2 = pega_n(0, s2, pos_p);
  d2 = pega_d(pos_p, s2);
  n1 += n2; d1 += d2; dec = d1*100;
  printf("cpf %s\n", cpf);
  printf("%llu.", n1);
  if(dec>0 && dec<10) printf("0");
  printf("%d", dec);
  if(dec==0) printf("0");
  printf("\n");
  return 0;
}
