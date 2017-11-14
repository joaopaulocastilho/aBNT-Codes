#include <stdio.h>
#include <map>

using namespace std;

#define MAX 112

int main(void){
  int n;
  char str[MAX];
  map <string, int> names;
  
  scanf("%d", &n);

  while(n--){
    scanf("%s", str);
    if(names.find(str) == names.end()){
      names[str] = 0;
      printf("OK\n");
    }
    else{
      names[str]++;
      printf("%s%d\n", str, names[str]);
    }
  }

  return 0;
}
