#include <iostream>

using namespace std;

#define MAX 1123

int n, m, c;

int valido(int x){
  if(x < 0) return 0;
  else if(x >= n) return n - 1;
  return x;
}

int main(void){
  int matrix[MAX][MAX];
  cin >> n >> m >> c;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> matrix[i][j];
    }
  }
  int cumpridas = 1, anterior = 0;
  for(int i = 0; i < m; i++){
    int tem = 0;
    for(int j = 0; j < n; j++){
      if(matrix[j][i] != 0 && anterior == 1) cumpridas = 0;
      if(matrix[j][i] != 0) tem = 1;
    }
    if(tem) anterior = 1;
    else anterior = 0;
  }
  if(!cumpridas){ cout << "N\n"; return 0; }
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(matrix[i][j] == 1){
	for(int k = valido(i - c); k <= valido(i + c); k++){
	  if(k != i && matrix[k][j] == 1) cumpridas = 0;
	}
	if(!cumpridas){ cout << "N\n"; return 0; }
      }
      if(matrix[i][j] == 2){
	for(int k = valido(i - c); k <= valido(i + c); k++){
	  if(k != i && matrix[k][j] == 2) cumpridas = 0;
	}
	if(!cumpridas){ cout << "N\n"; return 0; }
      }
    }
  }
  cout << "S\n";
  return 0;
}
