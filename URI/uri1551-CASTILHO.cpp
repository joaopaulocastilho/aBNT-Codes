#include<stdio.h>
#include<string.h>

#define MAX 1123
#define valida(c) ((c) >= 'a' && (c) <= 'z')

char str[MAX];

int verifica_frase(void) {
  int v[30], tam = (int)strlen(str), ret = 0, i;
  memset(v, 0, sizeof(v));
  for (i = 0; i < tam; i++) if (valida(str[i])) v[str[i] - 'a']++;
  for (i = 0; i < 26; i++) ret += (v[i] > 0);
  return (ret < 13) ? 0 : ((ret == 26) ? 2 : 1);
}

int main(void) {
  int n, estado;
  scanf("%d ", &n);
  while (n--) {
    fgets(str, MAX, stdin); estado = verifica_frase();
    printf("frase %s\n", (estado == 0) ? "mal elaborada" :
           ((estado == 1) ? "quase completa" : "completa"));
  }
  return 0;
}
