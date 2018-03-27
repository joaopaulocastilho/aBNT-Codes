#include <cstdio>

int main(void){
  int a, b, c, found, tc;
  scanf("%d", &tc);
  while(tc--){
    found = 0;
    scanf("%d %d %d", &a, &b, &c);
    for(int ai = -100; ai <= 100 && !found; ai++)
      for(int bi = ai+1; bi <= 100 && !found; bi++)
	for(int ci = bi+1; ci <= 100 && !found; ci++){
	  if(ai+bi+ci != a) continue;
	  if(ai*bi*ci != b) continue;
	  if(ai*ai + bi*bi + ci*ci != c) continue;
	  found = 1;
	  printf("%d %d %d\n", ai, bi, ci);
	}
    if(!found) printf("No solution.\n");
  }
  return 0;
}
