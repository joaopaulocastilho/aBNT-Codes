#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef vector<int> vi;

int main(void){
  int i, j, k, n, perm, first = 1;
  vector<int> scores;
  
  for(i = 0; i <= 20; i++){
    if(find(scores.begin(), scores.end(), i) == scores.end()) scores.push_back(i);	
    if(find(scores.begin(), scores.end(), 2*i) == scores.end()) scores.push_back(2*i);
    if(find(scores.begin(), scores.end(), 3*i) == scores.end()) scores.push_back(3*i);
  }
  scores.push_back(50);
  //sort(scores.begin(), scores.end()); for(i = 0; i < scores.size(); i++) printf("%d ", scores[i]); printf("\n");
  
  while(scanf("%d", &n), n > 0){
    set <vi> comb;
    for(perm = i = 0; i < scores.size(); i++)
      for(j = 0; j < scores.size(); j++)
	for(k = 0; k < scores.size(); k++){
	  if(n - scores[i] - scores[j] - scores[k] == 0){
	    vi ncomb;
	    ncomb.push_back(scores[i]); ncomb.push_back(scores[j]); ncomb.push_back(scores[k]);
	    sort(ncomb.begin(), ncomb.end());
	    comb.insert(ncomb);
	    perm++;
	  }
	}
    if(first) first = 0;
    else printf("**********************************************************************\n");
    if(perm == 0) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
    else{
      printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, (int)comb.size());
      printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, perm);
    }
  }
  printf("**********************************************************************\n");
  printf("END OF OUTPUT\n");
  return 0;
}
