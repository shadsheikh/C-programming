#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"


void print_hand(deck_t * hand){
  for (int i=0 ;i<hand -> n_cards ;i++){
    print_card(*hand->cards[i]);
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  for (int i=0 ;i< d -> n_cards ;i++) {
    if (d->cards[i]->value == c.value && d->cards[i]->suit == c.suit){
      return 1;
    }
  }
  return 0;
}

void swap (deck_t * deck ,int c1,int c2){
  card_t * temp = deck->cards[c1];
  deck->cards[c1] = deck->cards[c2];
  deck->cards[c2] = temp;
}

  
void shuffle(deck_t * d){
  card_t ** card =d -> cards;
  card_t * temp;
  size_t n=d ->n_cards;
  int randarry;
  for (size_t i=0 ;i< n/2 ;i++) {
    randarry= random()%(n-i)+i;
    temp=card[i];
    card[i]=card[randarry];
    card[randarry]=temp;
  }
}

void assert_full_deck(deck_t * d) {
  for (int i=0 ;i<52 ;i++) {
    assert(deck_contains(d,card_from_num(i)));
  }
}

void add_card_to(deck_t * deck,card_t c) {

  card_t* c1=malloc(sizeof(*c1));
  c1->value = c.value;
  c1-> suit = c.suit;
  deck ->cards= realloc(deck->cards,(deck ->n_cards + 1)*sizeof(*deck ->cards));
deck ->cards[deck ->n_cards]=c1;
deck ->n_cards ++;
}

card_t * add_empty_card(deck_t * deck){

  card_t* c1=malloc(sizeof(*c1));

  c1->value = 0;
  c1->suit = 0;

  deck ->cards= realloc(deck->cards,(deck ->n_cards + 1)*sizeof(*deck ->cards));

  deck ->cards[deck ->n_cards]=c1;

  deck ->n_cards ++;

  return c1;

}

deck_t * make_deck_exclude(deck_t * excluded_cards){

  deck_t* ans=malloc(sizeof(*ans));

  ans->cards=NULL;

  ans->n_cards=0;

  for(unsigned i=0;i<52;i++){

    card_t c= card_from_num(i);

    if(!deck_contains(excluded_cards,c)) add_card_to(ans,c);

  }

  return ans;

}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) {
  deck_t* deck=malloc(sizeof(*deck));
  deck->n_cards=0;
  deck->cards=NULL;
  for (size_t i=0 ; i<n_hands ;i++) {

    for(int x=0 ;x<hands[i]->n_cards ;x++) {
      deck->cards=realloc(deck->cards,(deck->n_cards+1)*sizeof(*deck->cards));
      deck->cards[deck ->n_cards]=hands[i]->cards[x];
      deck->n_cards ++;
    }
  }

  deck_t* deck2=make_deck_exclude(deck);
  free(deck->cards);
  free(deck);
  return deck2;

}

void free_deck(deck_t * deck) {
  for(int i=0 ;i<deck->n_cards;i++){
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);

}

