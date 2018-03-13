#include <cstdio>
#include <cstring>

#define MAXN 100001
#define MAX 1123
//#define DEBUG

int getPA(int nums[]){
  int num = 1, i = 1;
  nums[0] = 1;
  while(num < MAXN){
    num += 2 * i + 1;
    nums[i++] = num;
  }
  return i;
}

void clear(char word[], int &len){
  for(int i = 0; i < len; i++)
    if(word[i] < 'a' || word[i] > 'z'){
      for(int j = i; j < len; j++)
	word[j] = word[j+1];
      i--; len--;
    }
}

int main(void){
  int nums[MAXN], idx, tc, i, j, k, caso = 1;
  char word[MAXN], matrix[MAX][MAX];
  idx = getPA(nums);
  scanf("%d", &tc);
  getchar();
  while(tc--){
    printf("Case #%d:\n", caso++);
    fgets(word, MAXN, stdin);
    int len = strlen(word);
    word[len-1] = '\0';
    len--;
    clear(word, len);
    if(!len){ printf("0\n"); continue; }
    for(i = 0; i < idx; i++) if(len == nums[i]) break;
    if(i == idx){ printf("No magic :(\n"); continue; }
    int count = 0;
    for(j = 0; j < i+1; j++){
      for(k = 0; k < i+1; k++){
	matrix[j][k] = word[count++];
      }
    }
#ifdef DEBUG
    for(j = 0; j < i+1; j++){
      for(k = 0; k < i+1; k++)
	printf("%c ", matrix[j][k]);
      printf("\n");
    }
#endif
    int palin = 1;
    count = 0;
    for(j = 0; j < i+1; j++)
      for(k = 0; k < i+1; k++){
	if(word[count] != matrix[j][k]) palin = 0;
	if(word[count++] != matrix[k][j]) palin = 0;
      }
    count = 0;
    for(j = i; j >= 0; j--)
      for(k = i; k >= 0; k--){
	if(word[count] != matrix[j][k]) palin = 0;
	if(word[count++] != matrix[k][j]) palin = 0;
      }
    if(palin) printf("%d\n", i+1);
    else printf("No magic :(\n");
  }
  return 0;
}
