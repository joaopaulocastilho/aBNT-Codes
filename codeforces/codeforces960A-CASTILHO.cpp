#include <stdio.h>
#include <string.h>

#define MAX 5123

int main(void) {
  int resp = 1, qtda = 0, qtdb = 0, qtdc = 0, oa = 0, ob = 0, oc = 0;
  int tam, i;
  char s[MAX];
  scanf("%s", s); tam = strlen(s);
  for (i = 0; i < tam; i++) {
    if (s[i] == 'a') {
      if (ob || oc) { resp = 0; break; }
      oa = 1; qtda++; }
    else if (s[i] == 'b') {
      if (!oa) { resp = 0; break; }
      if (oc) { resp = 0; break; }
      ob = 1; qtdb++;
    } else {
      if (!ob) { resp = 0; break; }
      oc = 1; qtdc++;
    }}
  if (!ob) resp = 0;
  if (!resp || (qtdc != qtda && qtdc != qtdb)) printf("NO\n");
  else printf("YES\n");
  return 0;
}
