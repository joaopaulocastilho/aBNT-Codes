#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 112345

typedef struct node{
  char str[MAX];
  node *next;
} node;

int j, put;
char str[MAX];
node *head = NULL, *tail, *newn;

void print(){
  for(node *p = head; p != NULL; p = p->next){
    for(int i = 0; i < (int)strlen(p->str); i++)
      if(p->str[i] != '\n') printf("%c", p->str[i]);
  }
}

void addi(){
  if(j == 0) return;
  newn = (node*) malloc(sizeof(node));
  newn->next = NULL;
  for(int i = 0; i <= j; i++)
    newn->str[i] = str[i];
  if(head->str[0] == '1'){
    head = newn; tail = head;
  }
  else if(put){
    if(tail == NULL) tail = newn;
    else{
      tail->next = newn; tail = newn;
    }
  }
  else{
    newn->next = head; head = newn;
  }
}

void clear(){
  node *aux;
  for(node *p = head; p->next != NULL; p = aux){
    aux = p->next;
    free(p);
  }
  head = (node*) malloc(sizeof(node));
  head->str[0] = '1';
  head->next = NULL;
  tail = head;
}


int main(void){
  char c;
  j = 0;
  put = 1;
  head = (node*) malloc(sizeof(node));
  head->str[0] = '1';
  head->next = NULL;
  tail = head;
  while(scanf("%c", &c) != EOF){
    if(c == '\n'){
      if(j != 0){
	str[j] = '\0';
	//for(int i = 0; i < j; i++) printf("%c", str[i]); printf("\n");
	addi();
	j = 0;
      }
      print();
      printf("\n");
      clear();
    }
    if(c != '[' && c !=  ']') str[j++] = c;
    else if(c == '['){
      str[j] = '\0';
      addi();
      j = 0;
      put = 0;
    }
    else if(c == ']'){
      str[j] = '\0';
      addi();
      j = 0;
      put = 1;
    }
  }
  return 0;
}
