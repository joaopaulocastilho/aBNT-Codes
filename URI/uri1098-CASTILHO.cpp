#include <stdio.h>

int main(void) {
  int ii, ji, id, jd, flag = 0, npara = 1;
  for (ii = 0, id = 0, jd = 0; npara; ) {
    for (ji = 1 + ii; ji <= 3 + ii; ji++) {
      printf("I=%d", ii);
      if (id) printf(".%d", id);
      printf(" J=%d", ji);
      if (id) printf(".%d", id);
      printf("\n");
    }
    id += 2;
    if (id == 10) { ii++; ji++; id = jd = 0; }
    if (flag) npara = 0;
    if (ii == 2) flag = 1;
  }
  return 0;
}
