#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "input.h"
#include "future.h"
#include "deck.h"
#include "cards.h"

size_t strToInt(char * str){
  size_t len = strlen(str);
  size_t res = 0;
  size_t delta = 0;
  for(size_t i=0; i<len; i++){
    delta = str[i] - '0';
    for(size_t j=0; j<len-i-1; j++){
      delta = delta * 10;
    }
    res = res + delta;
  }
  return res;
}

void lineToStr(char * line){
  size_t len = strlen(line);
  if(line[len-1] == '\n'){
    line[len-1] = '\0';
  }
}

int getLastIndex(const char * str, int fstIdx){
  char c = str[fstIdx];
  int count = 0;
  while(isalpha(c) || isdigit(c) || (c=='?')){
    count++;
    c = str[fstIdx + count];
  }
  if(count <=1 ){
    return -1;
  }
  return fstIdx+count;
}


deck_t * hand_from_string(const char * str, future_cards_t * fc){
  deck_t *ans=malloc(sizeof(*ans));
  assert(ans!=NULL);
  ans->cards=NULL;
  ans->n_cards=0;
  size_t i=0;
  while(str[i]!='\0'){
    if(str[i]=='?' && isdigit(str[i+1])){
      char *number=malloc(2*sizeof(*number));
      assert(number!=NULL);
      size_t j=0;
      number[j++]=str[i+1];
      number[j]='\0';
      if(isdigit(str[i+2])){
	number=realloc(number,3*sizeof(*number));
	assert(number!=NULL);
	number[j++]=str[i+2];
	number[j]='\0';
	i++;
      }
      add_future_card(fc,atoi(number),add_empty_card(ans));
      free(number);
    }
    else if((isdigit(str[i]) || str[i]=='A' || str[i]=='K' || str[i]=='Q' || str[i]=='J') && (str[i+1]=='s' || str[i+1]=='h' || str[i+1]=='d' || str[i+1]=='c')){
      add_card_to(ans,card_from_letters(str[i],str[i+1]));
    }
    else{
      fprintf(stderr,"Error: Invalid input file format, line %s",str);
      card_from_letters(0,0);
    }
    i++;
    while(isspace(str[i+1]) && str[i+1]!='\0'){
      i++;
    }
    /*else if(str[i+1]=='\0'){
      break;
    }
    else{
      fprintf(stderr,"Error: Invalid input file format, line '%s'\n",str);
      card_from_letters(0,0);
      }*/
    i++;
  }
  return ans;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc){
  deck_t **ans=NULL;
  /**n_hands=0;*/

  char *line=NULL;
  size_t sz=0;
  while(getline(&line,&sz,f)>=0){
    char *p=strchr(line,'\n');
    if(p!=NULL){
      *p='\0';
    }
    else{
      fprintf(stderr,"Error: Invalid line '%s' in input file!\n",line);
      assert(p!=NULL);
    }
    ans=realloc(ans,((*n_hands)+1)*sizeof(*ans));
    assert(ans!=NULL);
    (*n_hands)++;
    ans[(*n_hands)-1]=hand_from_string(line,fc);
    if(ans[(*n_hands)-1]->n_cards<5){
      fprintf(stderr,"Error: Invalid number of cards in input file\n");
      assert(ans[(*n_hands)-1]->n_cards>=5);
    }
    free(line);
    sz=0;
  }
  free(line);

  return ans;
}
