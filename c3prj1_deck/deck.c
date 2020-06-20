#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
#include "eval.c"
#include "cards.h"

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
  assert(deck != NULL);

  card_t * card=malloc(sizeof(*card));
  assert(card != NULL);

  card->value = c.value;
  card->suit  = c.suit;

  deck ->n_cards ++;
  deck ->cards  = realloc(deck->cards,deck ->n_cards*sizeof(deck->cards));
  deck ->cards[deck->n_cards]=card;
}

card_t * add_empty_card(deck_t * deck){

  assert(deck != NULL);
  
  card_t* empty_card = malloc(sizeof(*empty_card));

  empty_card->value = 0;
  empty_card->suit = 0;
  add_card_to(deck,*empty_card);
  free(empty_card);
  return  deck ->cards[deck ->n_cards-1];

}

deck_t * make_deck_exclude(deck_t * excluded_cards){

  deck_t* answer=malloc(sizeof(*answer));
  card_t card;
  answer->cards=NULL;
  answer->n_cards=0;

  for(int i=0;i<52;i++){

    card = card_from_num(i);

    if(!deck_contains(excluded_cards,card)){
      add_card_to (answer,card);
    
    }
  }

  return answer;

}

 void free_cards(deck_t * deck){
    for(int i=0;i<deck->n_cards;i++){
      free(deck->cards[i]);
    }
    free(deck->cards);
    deck->n_cards = 0;
    deck->cards=NULL;
  }
 

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) {
  deck_t temp;
  temp.cards = NULL;
  temp.n_cards = 0;
  
  for (int i=0 ; i<n_hands ;i++) {

    for(int j=0 ;j<hands[i]->n_cards ;j++) {
      if(!is_empty_card(hands[i]->cards[j])){
	  add_card_to(&temp,*hands[i]->cards[j]);
	}
       }
      }

  deck_t* answer = make_deck_exclude(&temp);
 
  free_cards(&temp);
  return answer;

}
 
void free_deck(deck_t * deck) {
    free_cards(deck);
   free(deck);
}

