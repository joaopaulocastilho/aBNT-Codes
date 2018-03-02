#include <cstdio>

int main(void){
  int tc;
  double v1, v2;
  scanf("%d", &tc);
  while(tc--){
    scanf("%lf %lf", &v1, &v2);
    if(v2 == 0) printf("divisao impossivel\n");
    else printf("%.1lf\n", v1/v2);
  }
  return 0;
}
