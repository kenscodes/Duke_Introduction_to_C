#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"



int com (card_t c1,card_t c2){
  if ((c1.value == c2.value) &&(c1.suit == c2.suit)) return 1;
  return 0;

}

void print_hand(deck_t * hand){
  card_t ** card =hand -> cards ;
  card_t  card1;
  for (size_t i=0 ;i<(hand -> n_cards );i++){
    card1=**(card +i);
    print_card(card1);
  }
}

int deck_contains(deck_t * d, card_t c) {
  card_t ** card =d -> cards ;
  for (size_t i=0 ;i< d -> n_cards ;i++){
    if (com(**(card+i),c)) return 1;
  }
  
  return 0;
}

void shuffle(deck_t * d){
  card_t ** card =d -> cards ;
  card_t * temp;
  size_t n=d ->n_cards;
  int randarry;
  for (size_t i=0 ;i< n/2 ;i++){
    randarry= random()%(n-i)+i;
    temp=card[i];
    card[i]=card[randarry];
    card[randarry]=temp;
  }  
}

void assert_full_deck(deck_t * d) {
  card_t ** card =d -> cards ;
  card_t c;
  int count;

  for (size_t i=0 ;i< d -> n_cards ;i++){
    c=**(card+i);
    count=0;
    for (size_t j=0 ;j< d -> n_cards ;j++){
      if(com(**(card+j), c)) count ++;
    }
    assert(count ==1);
  }

}

void add_card_to(deck_t * deck, card_t c){
  deck->cards=realloc(deck->cards,(deck->n_cards+1)*sizeof(*deck->cards));
  assert(deck->cards!=NULL);
  deck->n_cards++;
  deck->cards[deck->n_cards-1]=malloc(sizeof(**deck->cards));
  assert(deck->cards[deck->n_cards-1]!=NULL);
  deck->cards[deck->n_cards-1]->value=c.value;
  deck->cards[deck->n_cards-1]->suit=c.suit;
}

card_t * add_empty_card(deck_t * deck){
  card_t c={0,NUM_SUITS};
  add_card_to(deck,c);
  return deck->cards[deck->n_cards-1];
}

deck_t * make_deck_exclude(deck_t * excluded_cards){
  deck_t *ans=malloc(sizeof(*ans));
  assert(ans!=NULL);
  ans->cards=NULL;
  ans->n_cards=0;
  for(unsigned i=0;i<52;i++){
    card_t c=card_from_num(i);
    if(!deck_contains(excluded_cards,c)){
      add_card_to(ans,c);
    }
  }
  return ans;
}

void free_deck(deck_t * deck);

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands){
  deck_t *excluded=malloc(sizeof(*excluded));
  assert(excluded!=NULL);
  excluded->cards=NULL;
  excluded->n_cards=0;
  for(size_t i=0;i<n_hands;i++){
    for(size_t j=0;j<hands[i]->n_cards;j++){
      add_card_to(excluded,*hands[i]->cards[j]);
    }
  }
  deck_t *ans=make_deck_exclude(excluded);
  free_deck(excluded);
  return ans;
}

void free_deck(deck_t * deck){
  if(deck!=NULL){
    for(size_t i=0;i<deck->n_cards;i++){
      free(deck->cards[i]);
    }
    free(deck->cards);
    free(deck);
  }
}



