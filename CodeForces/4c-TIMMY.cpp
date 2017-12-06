#include <cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std;
#define MAX 123

int main(void){
  int tc;
  char name[MAX];
  map< string, int > mapa;
  scanf("%d", &tc);
  while(tc--){
    cin >> name;
    if(mapa[name]){
      printf("%s%d\n", name, mapa[name]++);
    }
    else{
      mapa[name] = 1;
      printf("OK\n");
    }
  }
  return 0;
}
