#include <cstdio>
#include <cstring>

#define MAX 1123

int main(void){
  int tc, len, guess, win, wrong, already, glen;
  char ans[MAX], word, guesses[MAX];
  while(scanf(" %d", &tc), tc != -1){
    glen = 0;
    win = wrong = 0;
    printf("Round %d\n", tc);
    scanf("%s", ans);
    len = strlen(ans);
    getchar();
    while(scanf("%c", &word), word != '\n' && wrong < 7 && !win){
      already = 0;
      for(int i = 0; i < glen; i++){
	if(guesses[i] == word){ already = 1; }
      }
      if(!already){
	guesses[glen++] = word;
	guess = 0;
	for(int i = 0; i < len; i++){
	  if(ans[i] == word){
	    for(int j = i; j <= len; j++){ ans[j] = ans[j+1]; }
	    i--;
	    guess = 1;
	    len--;
	  }
	}
	if(guess == 0) wrong++;
	if(len == 0) win = 1;
      }
    }
    if(wrong >= 7){ printf("You lose.\n");}
    else if(win){ printf("You win.\n");}
    else printf("You chickened out.\n");
    while(word != '\n') scanf("%c", &word);
  }
  return 0;
}
