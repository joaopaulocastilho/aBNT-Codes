#include <stdio.h>
#include <string.h>
#include <set>

using namespace std;

#define MAX 1123

int main(void){
  set <char> letters, wletters, guessed;
  int i, end, round, mistakes, difLetters;
  char word[MAX], guesses[MAX];

  while(scanf("%d", &round), round != -1){
    letters.clear(); wletters.clear();
    guessed.clear();
    difLetters = mistakes = 0;
    scanf("%s ", word);
    scanf("%s ", guesses);
    for(end = strlen(word), i = 0; i < end; i++){
      if(letters.find(word[i]) == letters.end()){
	letters.insert(word[i]);
	difLetters++;
      }
    }
    for(end = strlen(guesses), i = 0; i < end; i++){
      if(letters.find(guesses[i]) == letters.end() && wletters.find(guesses[i]) == wletters.end()){
	wletters.insert(guesses[i]);
	mistakes++;
      }
      else if(letters.find(guesses[i]) != letters.end() && guessed.find(guesses[i]) == guessed.end()){
	guessed.insert(guesses[i]);
	difLetters--;
	if(difLetters == 0) break;
      }
    }
    printf("Round %d\n", round);
    if(mistakes >= 7) printf("You lose.\n");
    else if(difLetters == 0) printf("You win.\n");
    else printf("You chickened out.\n");
  }
  
  return 0;
}
