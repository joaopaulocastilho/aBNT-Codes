#include <bits/stdc++.h>

int main(void){
  int grade;

  scanf("%d", &grade);
  if(grade >= 86) printf("A\n");
  else if(grade >= 61) printf("B\n");
  else if(grade >= 36) printf("C\n");
  else if(grade >= 1) printf("D\n");
  else printf("E\n");

  return 0;
}
