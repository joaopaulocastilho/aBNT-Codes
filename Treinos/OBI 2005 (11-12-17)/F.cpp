#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mao;


int testaSeq(){
  int i, seq = 1;
  for(i = 0; i < 4; i++)
    if(mao[i] != mao[i+1]-1) seq = 0;
  if(seq) return mao[0] + 200;
  return -1;
}

int testaQuadra(){
  if(mao[0] == mao[1] && mao[1] == mao[2] && mao[2] == mao[3] ||
     mao[1] == mao[2] && mao[2] == mao[3] && mao[3] == mao[4]) return mao[2] + 180;
  return -1;
}

int testaFull(){
  if(mao[0] == mao[1] && mao[1] == mao[2] && mao[3] == mao[4] ||
     mao[2] == mao[3] && mao[3] == mao[4] && mao[0] == mao[1]) return mao[2] + 160;
  return -1;
}

int testaTrinca(){
  if(mao[0] == mao[1] && mao[1] == mao[2] ||
     mao[1] == mao[2] && mao[2] == mao[3] ||
     mao[2] == mao[3] && mao[3] == mao[4]) return mao[2] + 140;
  return -1;
}

int testaDoisPares(){
  if(mao[1] == mao[2] && mao[3] == mao[4] ||
     mao[0] == mao[1] && mao[3] == mao[4] ||
     mao[0] == mao[1] && mao[2] == mao[3]) return 3 * max(mao[1], mao[3]) + 2 * min(mao[1], mao[3]) + 20;
  return -1;
}

int testaPar(){
  if(mao[0] == mao[1] ||
     mao[1] == mao[2]) return mao[1];
  if(mao[2] == mao[3] ||
     mao[3] == mao[4]) return mao[3];
  return -1;
}

int main(void){
  int i, n, carta, ans, caso = 1;

  scanf("%d", &n);
  while(n--){
    mao.clear();
    for(i = 0; i < 5; i++){
      scanf("%d", &carta);
      mao.push_back(carta);
    }
    sort(mao.begin(), mao.end());
    printf("Teste %d\n", caso++);
    //for(i = 0; i < 5; i++) printf("%d ", mao[i]);
    //printf("\n");

    if((ans = testaSeq()) != -1) printf("%d\n", ans);
    else if((ans = testaQuadra()) != -1) printf("%d\n", ans);
    else if((ans = testaFull()) != -1) printf("%d\n", ans);
    else if((ans = testaTrinca()) != -1) printf("%d\n", ans);
    else if((ans = testaDoisPares()) != -1) printf("%d\n", ans);
    else if((ans = testaPar()) != -1) printf("%d\n", ans);
    else printf("0\n");
    printf("\n");
  }
  
  return 0;
}
