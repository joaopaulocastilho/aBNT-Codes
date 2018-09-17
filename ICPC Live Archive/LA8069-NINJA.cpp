#include <bits/stdc++.h>

const int MAX = 21234;

char rotate(char c, int num){
  return 'A' + ((c - 'A' + num) % 26);
}

int main(void){
  int half, sum, end, i, j;
  char str[MAX];
  
  while (scanf("%s ", str) != EOF){
    end = strlen(str);
    half = end/2;
    for(sum = i = 0; i < half; i++) sum += str[i] - 'A';
    for(i = 0; i < half; i++) str[i] = rotate(str[i], sum);
    for(sum = 0, i = half; i < end; i++) sum += str[i] - 'A';
    for(i = half; i < end; i++) str[i] = rotate(str[i], sum);
    for(i = 0, j = half; i < half; i++, j++) str[i] = rotate(str[i], str[j] - 'A');
    str[half] = 0;
    printf("%s\n", str);
  }

  return 0;
}
