#include <cstdio>

char a, b, c, d;

void aumenta1(char &a, char &b, char &c, char &d){
  if(d == '9'){
    d = '0';
    if(c == '9'){
      c = '0';
      if(b == '9'){
	b = '0';
	if(a == '9'){
	  a = '0';
	  printf("1");
	}
	else a++;
      }
      else b++;
    }
    else c++;
  }
  else d++;
}

int main(void){
  char ano[3];
  int distintos = 0;
  scanf("%s", ano);
  a = ano[0];
  b = ano[1];
  c = ano[2];
  d = ano[3];
  aumenta1(a, b, c, d);
  while(!distintos){
    if(a != b && a != c && a != d && b != c && b != d && c != d){ distintos = 1; }
    else aumenta1(a, b, c, d);
  }
  printf("%c%c%c%c\n", a, b, c, d);
  return 0;
}
