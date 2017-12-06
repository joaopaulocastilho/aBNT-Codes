#include <cstdio>
#include <cstring>

#define MAX 112

int main(void){
  char junk[MAX], grtstr[MAX], str[MAX];
  int n, p, greater, qtt;
  double price, grtprice;
  for(int i = 1; scanf("%d %d", &n, &p), n != 0 && p != 0; i++){
    for(int j = 0; j < MAX; j++) grtstr[j] = '\0';
    greater = -1;
    grtprice = -1;
    printf("%sRFP #%d\n", i > 1 ? "\n" : "", i);
    getchar();
    while(n--) fgets(junk, MAX, stdin); 
    while(p--){
      fgets(str, MAX, stdin);
      scanf("%lf %d", &price, &qtt);
      if(qtt > greater){
	strcpy(grtstr, str);
	grtprice = price;
	greater = qtt;
      }
      else if(qtt == greater)
	if(price < grtprice){
	  strcpy(grtstr, str);
	  grtprice = price;
	  greater = qtt;
	}
      getchar();
      while(qtt--) fgets(junk, MAX, stdin);
    }
    printf("%s", grtstr);
  }
  return 0;
}
