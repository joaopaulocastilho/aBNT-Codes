#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>


using namespace std;

int main(void){
  set<int> cjt;
  int count, tsum, num;
  set<vector<int> > ans;
  vector <int> nums;  
  for(int i = 1; i <= 20; i++){
    cjt.insert(i);
    cjt.insert(2*i);
    cjt.insert(3*i);
  }
  cjt.insert(50);
  cjt.insert(0);
  while(scanf("%d", &num), num > 0){
    nums.clear();
    ans.clear();
    count = 0;
    for(set<int>::iterator it1 = cjt.begin(); it1 != cjt.end(); ++it1)
      for(set<int>::iterator it2 = cjt.begin(); it2 != cjt.end(); ++it2)
	for(set<int>::iterator it3 = cjt.begin(); it3 != cjt.end(); ++it3){
	  tsum = (*it1) + (*it2) + (*it3);
	  if(tsum == num){
	    nums.push_back(*it1);
	    nums.push_back(*it2);
	    nums.push_back(*it3);
	    sort(nums.begin(), nums.end());
	    ans.insert(nums);
	    count++;
	    nums.clear();
	  }
	}
    if(count == 0) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", num);
    else
      printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\nNUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", num, ans.size(), num, count);
    printf("**********************************************************************\n");
  }
  printf("END OF OUTPUT\n");
  return 0;
}
