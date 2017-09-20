#include <stdio.h>

#define EPS 10e-9

int main(void){
  char c;
  int palavra=0, contp=0, nsim=0, flage=0, flagp=0;
  double avg=0;
  while(scanf("%c", &c) != EOF){
    if(c=='\n'){
      if(palavra){
	avg+=nsim;
	contp++;
      }
      //printf("M = [%.3lf] CONT=[%d] media=[%.3lf]\n", avg, contp, avg/contp);
      if(contp==0) printf("250\n");
      else if((avg/contp)>=6) printf("1000\n");
      else if((avg/contp)>=4) printf("500\n");
      else printf("250\n");
      contp=0; palavra=0; avg=0; nsim=0; flagp=0; flage=0;
    }
    else if(c==' '){
      if(palavra){
	avg+=nsim;
	contp++;
      }
      nsim=0; palavra = 0; flage=0; flagp=0;
    }
    else if(!flage && !flagp &&
	    ((c>='a' && c<='z') || (c>='A' && c<='Z') || ((c=='.') && nsim>0))){
      if(c!='.'){ nsim++; palavra=1; }
      if(c=='.') flagp=1;
      //printf(" CHAR = [%c] nsim = [%d] contp = [%d] avg = [%.3lf]\n", c, nsim, contp, avg);
    }
    else{ palavra=0; nsim=0; flage=1; }
  }
  return 0;
}
