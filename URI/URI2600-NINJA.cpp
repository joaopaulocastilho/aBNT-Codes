#include <stdio.h>
#include <string.h>

int main(void){
  int i, t, faces[6], check[10], togo;
  
  scanf("%d", &t);
  while(t--){
    memset(check, 0, sizeof(check));
    togo = 6;
    for(i = 0; i < 6; i++){
      scanf("%d", &faces[i]);
      if(faces[i] >= 1 && faces[i] <= 6 && !check[faces[i]]){ check[faces[i]] = 1; togo--;}
    }
    //printf("%d\n", togo);
    if(faces[0] + faces[5] == 7 && faces[1] + faces[3] == 7 && faces[2] + faces[4] == 7 && !togo) printf("SIM\n");
    else printf("NAO\n");
  }
  

  return 0;
}
