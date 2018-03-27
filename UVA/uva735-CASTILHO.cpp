#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main(void) {
  int n, i, resp;
  set<int>pos;
  vi vr(3);
  for (i = 1; i <= 20; i++) {
    if (pos.find(i * 2) == pos.end()) pos.insert(i);
    if (pos.find(i * 2) == pos.end()) pos.insert(i * 2);
    if (pos.find(i * 3) == pos.end()) pos.insert(i * 3);
  }
  if (pos.find(0) == pos.end()) pos.insert(0);
  if (pos.find(50) == pos.end()) pos.insert(50);
  while (scanf("%d", &n), n > 0) {
    set<vi>comb; resp = 0;
    for (set<int>::iterator it1 = pos.begin(); it1 != pos.end(); ++it1)
      for (set<int>::iterator it2 = pos.begin(); it2 != pos.end(); ++it2)
        for (set<int>::iterator it3 = pos.begin(); it3 != pos.end(); ++it3)
          if (*it1 + *it2 + *it3 == n) {
            vr[0] = *it1; vr[1] = *it2; vr[2] = *it3;
            sort(vr.begin(), vr.end());
            resp++;
            if (comb.find(vr) == comb.end()) comb.insert(vr);
          }
    if (resp) {
      printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",
             n, (int)comb.size());
      printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",
             n, resp);
    } else printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
    printf("**********************************************************************\n");
  }
  printf("END OF OUTPUT\n");
  return 0;
}
