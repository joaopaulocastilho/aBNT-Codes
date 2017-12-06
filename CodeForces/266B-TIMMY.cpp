#include <cstdio>


int main(void){
  char str[55], c;
  int n, t;
  scanf("%d %d", &n, &t);
  scanf("%s", str);
  while(t--)
    for(int i = 0; i < n; i++)
      if(str[i] == 'B' && str[i+1] == 'G'){
	c = str[i];
	str[i] = str[i+1];
	str[i+1] = c;
	i++;
      }
  printf("%s\n", str);
  return 0;
}
