#include <cstdio>
#include <vector>

using namespace std;

#define MAX 30

int d, sumTime, flag = 0;

void aumenta1(int pos, vector<int> minTime, vector<int> maxTime, int sum, vector<int> study){
  if(pos >= d) return;
  if(study[pos]+1 > maxTime[pos]){ aumenta1(pos+1, minTime, maxTime, sum, study); return; }
  if(sum + 1 == sumTime){
    printf("YES\n");
    flag = 1;
    study[pos] += 1;
    for(int i = 0; i < d; i++){
      printf("%d", study[i]);
      if(i != d-1) printf(" ");
    }
    printf("\n");
    return;
  }
  sum++;
  study[pos] += 1;
  aumenta1(pos, minTime, maxTime, sum, study);
  return;
}

int main(void){
  int sumMin, sumMax;
  vector<int> minTime;
  vector<int> maxTime;
  vector<int> study(MAX);
  for(int i = 0; i < d; i++) study[i] = 0;
  int min, max;
  sumMin = 0, sumMax = 0;
  scanf("%d %d", &d, &sumTime);
  for(int i = 0; i < d; i++){
    scanf("%d %d", &min, &max);
    minTime.push_back(min);
    study[i] = minTime[i];
    maxTime.push_back(max);
    sumMin += min; sumMax += max;
  }
  if(sumMin > sumTime || sumMax < sumTime){ printf("NO\n"); return 0; }
  if(sumTime == sumMin){
    printf("YES\n");
    for(int i = 0; i < d; i++){
      printf("%d", study[i]);
      if(i != d-1) printf(" ");
    }
    printf("\n");
  }
  aumenta1(0, minTime, maxTime, sumMin, study);
  return 0;
}
