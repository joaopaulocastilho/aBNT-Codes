typedef struct { int x, y; }ponto_t; //Struct que define um ponto

//Dados 3 pontos, qual a área do triângulo formado por eles?
double area(ponto_t a, ponto_t b, ponto_t c) {
  int r1, r2, ret;
  r1 = a.x * b.y + a.y * c.x + b.x * c.y;
  r2 = c.x * b.y + c.y * a.x + b.x * a.y;
  ret = abs(r1 - r2);
  return (double)ret / 2.;
}
