#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  vector<int> students;
  int student, n;
  int intervalo;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &student);
    students.push_back(student);
  }
  scanf("%d", &intervalo);
  sort(students.begin(), students.end());
  int maiorcount = 1, count;
  for(int i = 0; i < n; i++){
    count = 1;
    for(int j = i+1; j < n; j++){
      if((students[j] - students[i]) <= intervalo){
	count++;
 	if(maiorcount < count) maiorcount = count;
      }
      else{
	break;
      }
    }
  }
  printf("%d\n", maiorcount);
  return 0;
}
