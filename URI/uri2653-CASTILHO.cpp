#include<stdio.h>
#include<string.h>
#include<string>
#include<set>
using namespace std;

#define MAX 1123456

int main(void) {
  int resp = 0;
  char joia[MAX];
  set<string>j;
  while (fgets(joia, MAX, stdin)) {
    joia[strlen(joia) - 1] = '\0';
    if (j.find(string(joia)) == j.end()) {
      j.insert(string(joia));
      resp++;
    }
  }
  printf("%d\n", resp);
  return 0;
}
