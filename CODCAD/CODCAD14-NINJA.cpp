#include <stdio.h>

int main(void){
  int cv, ce, cs, fv, fe, fs, cor, fla;

  scanf("%d %d %d %d %d %d", &cv, &ce, &cs, &fv, &fe, &fs);
  cor = cv * 3 + ce;
  fla = fv * 3 + fe;
  if(cor == fla){
    if(cs == fs) printf("=\n");
    else printf("%c\n", cs > fs ? 'C' : 'F');
  }
  else printf("%c\n", cor > fla ? 'C' : 'F');
  
  return 0;
}
