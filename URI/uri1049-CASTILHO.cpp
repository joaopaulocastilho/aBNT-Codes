#include<stdio.h>
#include<string.h>

int main(void) {
  char str[112];
  int vert = 0, f1 = 0;
  fgets(str, 112, stdin);
  if (str[0] == 'v') vert = 1;
  fgets(str, 112, stdin);
  if (vert){ if (str[0] == 'a') f1 = 1; }
  else if (str[0] == 'i') f1 = 1;
  fgets(str, 112, stdin);
  if (vert) {
    if (f1) printf("%s\n", (str[0] == 'c') ? "aguia" : "pomba");
    else printf("%s\n", (str[0] == 'o') ? "homem" : "vaca");
  } else {
    if (f1) printf("%s\n", (str[2] == 'm') ? "pulga" : "lagarta");
    else printf("%s\n", (str[0] == 'h') ? "sanguessuga" : "minhoca");
  }
  return 0;
}
