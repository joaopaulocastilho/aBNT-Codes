#include <cstdio>

int main(void){
  int i;
  float v[3], a, b, c;
  for(i = 0; i < 3; i++){ scanf("%f", &v[i]); }
  if(v[0] >= v[1] && v[0] >= v[2]){
    a = v[0];
    b = v[1] >= v[2] ? v[1] : v[2];
    c = v[1] >= v[2] ? v[2] : v[1];
    }
  else if(v[1] >= v[0] && v[1] >= v[2]){
    a = v[1];
    b = v[0] >= v[2] ? v[0] : v[2];
    c = v[0] >= v[2] ? v[2] : v[0];
  }
  else if(v[2] >= v[0] && v[2] >= v[1]){
    a = v[2];
    b = v[0] >= v[1] ? v[0] : v[1];
    c = v[0] >= v[1] ? v[1] : v[0];
  }
  if(a >= b + c) return printf("NAO FORMA TRIANGULO\n");
  if((a * a) == (b * b) + (c * c)) printf("TRIANGULO RETANGULO\n");
  if((a * a) > (b * b) + (c * c)) printf("TRIANGULO OBTUSANGULO\n");
  if((a * a) < (b * b) + (c * c)) printf("TRIANGULO ACUTANGULO\n");
  if(a == b && a == c) printf("TRIANGULO EQUILATERO\n");
  if(a == b && a != c || a == c && a != b || b == c && b != a) printf("TRIANGULO ISOSCELES\n");
  return 0;
}
