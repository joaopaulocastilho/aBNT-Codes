#include <iostream>
#include <cstring>

using namespace std;

#define MAX 11

int matrix[MAX][MAX], flag;

void verifica3(int i, int j){
  int num[10];
  memset(num, 0, sizeof(num));
  for(int ni = i; ni < i + 3; ni++){
    for(int nj = j; nj < j + 3; nj++){
      num[matrix[ni][nj]] = 1;
    }
  }
  for(int k = 1; k <= 9; k++) if(num[k] == 0) flag = 0;
  //for(int k = 1; k <= 9; k++) cout << num[k] << " "; cout << endl;
}

void verifica9(){
  int num[10];
  for(int i = 0; i < 9; i++){
    memset(num, 0, sizeof(num));
    for(int j = 0; j < 9; j++)
      num[matrix[i][j]] = 1;
    for(int k = 1; k <= 9; k++) if(num[k] == 0) flag = 0;
  }
  //for(int k = 1; k <= 9; k++) cout << num[k] << " "; cout << endl;
  for(int i = 0; i < 9; i++){
    memset(num, 0, sizeof(num));
    for(int j = 0; j < 9; j++)
      num[matrix[j][i]] = 1;
    for(int k = 1; k <= 9; k++) if(num[k] == 0) flag = 0;
  }
  //for(int k = 1; k <= 9; k++) cout << num[k] << " "; cout << endl;
}

int main(void){  
  int tc; cin >> tc;
  for(int t = 1; t <= tc; t++){
    cout << "Instancia " << t << endl;
    flag = 1;
    for(int i = 0;i < 9; i++)
      for(int j = 0; j < 9; j++)
	cin >> matrix[i][j];
    for(int i = 0; i < 9; i += 3)
      for(int j = 0; j < 9; j += 3)
	verifica3(i, j);
    verifica9();
    if(flag) cout << "SIM\n\n";
    else cout << "NAO\n\n";
  }
  return 0;
}
