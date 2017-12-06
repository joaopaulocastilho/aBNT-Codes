#include <cstdio>
#include <cstring>

// 1 == +x;
// 2 == -x;
// 3 == +y;
// 4 == -y;
// 5 == +z;
// 6 == -z;

int main(void){
  int n, bended;
  char bend[3], straux[3];
  while(scanf("%d", &n), n != 0){
    bended = 1;
    for(int i = 1; i < n; i++){
      scanf(" %s", bend);
      straux[0] = 'N'; straux[1] = 'o'; straux[2] = '\0';
      if(strcmp(bend, straux) == 0) continue;
      
      straux[0] = '+'; straux[1] = 'z'; straux[2] = '\0';
      if(strcmp(bend, straux) == 0){
	//printf("%s\n", straux);
	if(bended == 1) bended = 5;
	else if(bended == 2) bended = 6;
	else if(bended == 5) bended = 2;
	else if(bended == 6) bended = 1;
	continue;
      }
      straux[0] = '-'; straux[1] = 'z'; straux[2] = '\0';
      if(strcmp(bend, straux) == 0){
	//printf("%s\n", straux);
	if(bended == 1) bended = 6;
	else if(bended == 2) bended = 5;
	else if(bended == 5) bended = 1;
	else if(bended == 6) bended = 2;
	continue;
      }
      straux[0] = '+'; straux[1] = 'y'; straux[2] = '\0';
      if(strcmp(bend, straux) == 0){
	//printf("%s\n", straux);
	if(bended == 1) bended = 3;
	else if(bended == 2) bended = 4;
	else if(bended == 3) bended = 2;
	else if(bended == 4) bended = 1;
	continue;
      }
      straux[0] = '-'; straux[1] = 'y'; straux[2] = '\0';
      if(strcmp(bend, straux) == 0){
	//printf("%s\n", straux);
	if(bended == 1) bended = 4;
	else if(bended == 2) bended = 3;
	else if(bended == 3) bended = 1;
	else if(bended == 4) bended = 2;
	continue;
      }
    }
    //printf("%d ", bended);
    switch(bended){
    case 1: printf("+x\n"); continue;
    case 2: printf("-x\n"); continue;
    case 3: printf("+y\n"); continue;
    case 4: printf("-y\n"); continue;
    case 5: printf("+z\n"); continue;
    case 6: printf("-z\n"); continue;
    }
  }  
  return 0;
}
