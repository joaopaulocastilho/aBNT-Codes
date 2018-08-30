#include <bits/stdc++.h>

using namespace std;

const int INF = 12345;
const int MAXOP = 4;
const int MAXP = 5;
const int MAXV = 5;

int v[MAXV];
int op[MAXOP], p[MAXP];


int c(int a, int b, int pos){
  if(op[pos] == 0) return a + b;
  if(op[pos] == 1) return a - b;
  if(op[pos] == 2) return a * b;
  if(b != 0 && (a % b) == 0) return (int)((double)a/(double)b);
  return INF;
}

int solve(){
  int ans;
  int qtd = INF;
  memset(op, 0, sizeof(op));
  memset(p, 0, sizeof(p));
  for(int j = 0; j < 4; j++){
    op[0] = j;
    for(int k = 0; k < 4; k++){
      op[1] = k;
      for(int l = 0; l < 4;l++){
	op[2] = l;
	for(int m = 0; m < 2; m++){
	  p[0] = m;
	  for(int n = 0; n < 2; n++){
	    p[1] = n;
	    for(int o = 0; o < 2; o++){
	      p[2] = o;
	      for(int q = 0; q < 2; q++){
		p[3] = q;
		for(int r = 0; r < 2; r++){
		  p[4] = r;
		  if(p[0]){
		    if(p[2]){
		      ans = c(c(v[0], v[1], op[0]), c(v[2], v[3], op[2]), op[1]);
		      if(ans == 24) qtd = min(qtd, 2); //cout << "Caso1\n"; }
		    }
		    else if(op[1] <= 1 && op[2] > 2){
		      ans = c(c(v[0], v[1], op[0]), c(v[2], v[3], op[2]), op[1]);
		      if(ans == 24) qtd = min(qtd, 1); //cout << "Caso2\n"; }
		    }
		    else{
		      ans = c(c(c(v[0],v[1], op[0]), v[2], op[1]), v[3], op[2]);
		      if(ans == 24) qtd = min(qtd, 1); //cout << "Caso3\n"; }
		    }
		  }
		  else if(p[1]){
		    if(p[3]){
		      ans = c(c(v[0], c(v[1], v[2], op[1]), op[0]),v[3], op[2]);
		      if(ans == 24) qtd = min(qtd, 2); //cout << "Caso4\n"; }
		    }
		    else if(p[4]){
		      ans = c(v[0], c(c(v[1], v[2], op[1]), v[3], op[2]), op[0]);
		      if(ans == 24) qtd = min(qtd, 2); //cout << "Caso5\n"; }
		    }
		    else if(op[2] > 1 && op[0] <= 1){
		      ans = c(v[0], c(c(v[1], v[2], op[1]),v[3], op[2]), op[0]);
		      if(ans == 24) qtd = min(qtd, 2); //cout << "Caso6\n"; }
		    }
		    else{
		      ans = c(c(v[0], c(v[1],v[2], op[1]), op[0]), v[3], op[2]);
		      if(ans == 24) qtd = min(qtd, 1); //cout << "Caso7\n"; }
		    }
		  }
		  else if(p[2]){
		    if(p[4]){
		      ans = c(v[0], c(v[1], c(v[2], v[3], op[2]), op[1]), op[0]);
		      if(ans == 24) qtd = min(qtd, 2); //cout << "Caso8\n"; }
		    }
		    else if(op[1] >=2 && op[0] < 2){
		      ans = c(v[0], c(v[1], c(v[2], v[3], op[2]), op[1]), op[0]);
		      if(ans == 24) qtd = min(qtd, 1); //cout << "Caso9\n"; }
		    }
		    else{
		      ans = c(c(v[0],v[1], op[0]), c(v[2], v[3], op[2]), op[1]);
		      if(ans == 24) qtd = min(qtd, 1); //cout << "Caso10\n"; }
		    }
		  }
		  else if(p[3]){
		    if(op[1] >= 2 && op[0] < 2){
		      ans = c(c(v[0], c(v[1],v[2], op[1]), op[0]), v[3], op[2]);
		      if(ans == 24) qtd = min(qtd, 1); //cout << "Caso11\n"; }
		    }
		    else{
		      ans = c(c(c(v[0],v[1], op[0]), v[2], op[1]), v[3], op[2]);
		      if(ans == 24) qtd = min(qtd, 1); //cout << "Caso12\n"; }
		    }
		  }
		  else if(p[4]){
		    if(op[2] >= 2 && op[1] < 2){
		      ans = c(v[0], c(v[1], c(v[2], v[3], op[2]), op[1]), op[0]);
		      if(ans == 24) qtd = min(qtd, 1); //cout << "Caso13\n"; }
		    }
		    else{
		      ans = c(v[0], c(c(v[1], v[2], op[1]), v[3], op[2]), op[0]);
		      if(ans == 24) qtd = min(qtd, 1); //cout << "Caso14\n"; }
		    }		      
		  }
		  else if(op[0] <= 1){
		    if(op[1] > 1){
		      if(op[2] <= 1){
			ans = c(c(v[0], c(v[1], v[2], op[1]), op[0]), v[3], op[2]);
			if(ans == 24) qtd = min(qtd, 0); //cout << "Caso15\n"; }
		      }
		      else if(op[2] > 1){
			ans = c(v[0], c(c(v[1], v[2], op[1]), v[3], op[2]), op[0]);
			if(ans == 24) qtd = min(qtd, 0); //cout << "Caso16\n"; }
		      }
		    }
		    else if(op[2] > 1){
		      ans = c(c(v[0], v[1], op[0]), c(v[2], v[3], op[2]), op[1]);
		      if(ans == 24) qtd = min(qtd, 0); //cout << "Caso17\n"; }
		    }
		    else{
		      ans = c(c(c(v[0],v[1], op[0]), v[2], op[1]), v[3], op[2]);
		      if(ans == 24) qtd = min(qtd, 0); //cout << "Caso18\n";
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
  return qtd;
}

int main(void){
  while(cin >> v[0]){
    for(int i = 1; i < 4; i++){
      cin >> v[i];
    }
    int ans = INF, add = 0, teste = 1;
    int aux[MAXV];
    ans = min(solve() + add, ans);
    for(int i = 0; i < 4; i++) aux[i] = v[i];
    
    add = 2;
    v[0] = aux[0]; v[1] = aux[1]; v[2] = aux[3]; v[3] = aux[2];
    ans = min(solve() + add, ans);

    add = 2;
    v[0] = aux[0]; v[1] = aux[2]; v[2] = aux[1]; v[3] = aux[3];
    ans = min(solve() + add, ans);

    add = 4;
    v[0] = aux[0]; v[1] = aux[2]; v[2] = aux[3]; v[3] = aux[1];
    ans = min(solve() + add, ans);

    add = 4;
    v[0] = aux[0]; v[1] = aux[3]; v[2] = aux[1]; v[3] = aux[2];
    ans = min(solve() + add, ans);

    add = 4;
    v[0] = aux[0]; v[1] = aux[3]; v[2] = aux[2]; v[3] = aux[1];
    ans = min(solve() + add, ans);

    add = 2;
    v[0] = aux[1]; v[1] = aux[0]; v[2] = aux[2]; v[3] = aux[3];
    ans = min(solve() + add, ans);

    add = 4;
    v[0] = aux[1]; v[1] = aux[0]; v[2] = aux[3]; v[3] = aux[2];
    ans = min(solve() + add, ans);

    add = 4;
    v[0] = aux[1]; v[1] = aux[2]; v[2] = aux[0]; v[3] = aux[3];
    ans = min(solve() + add, ans);

    add = 6;
    v[0] = aux[1]; v[1] = aux[2]; v[2] = aux[3]; v[3] = aux[0];
    ans = min(solve() + add, ans);

    add = 6;
    v[0] = aux[1]; v[1] = aux[3]; v[2] = aux[0]; v[3] = aux[2];
    ans = min(solve() + add, ans);

    add = 4;
    v[0] = aux[1]; v[1] = aux[3]; v[2] = aux[2]; v[3] = aux[0];
    ans = min(solve() + add, ans);
    
    if(ans == INF) cout << "impossible\n";
    else cout << ans << "\n";
  }

  return 0;
}
