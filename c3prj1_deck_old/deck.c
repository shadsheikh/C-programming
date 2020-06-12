#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  for(size_t i = 0; i < hand->n_cards; i++) {
    print_card(*hand->cards[i]); 
      printf(" ");
}

}
int deck_contains(deck_t * d, card_t c) {
  card_t chkCard;
  for(int i = 0; i < d->n_cards; i++) {
    chkCard.value = (*d->cards[i]).value;
    chkCard.suit = (*d->cards[i]).suit;
    if ((chkCard.value == c.value)&&(chkCard.suit == c.suit)) {
      return 1;
    }
  }

  return 0;
}

 int randSorter(const void * rand1_vp, const void * rand2_vp) {
   typedef struct randcard {
     card_t * card_p;
     long int rand;
   } cardRand;

   const cardRand * rand1_p = rand1_vp;
   const cardRand * rand2_p = rand2_vp;
   long int randDiff = rand1_p->rand - rand2_p->rand;

   return randDiff;
 }
 
   void shuffle(deck_t * d){
     size_t decksize = d->n_cards;
     typedef struct randcard{
       card_t * card_p;
       long int rand;
     }cardRand;
     cardRand deckRands[decksize];
     for(size_t i = 0; i < decksize; i++) {
       deckRands[i].card_p = d->cards[i];
       deckRands[i].rand = random();
     }
     qsort(deckRands, decksize , sizeof(cardRand) , randSorter);
     for(size_t i = 0; i < decksize; i++) {
       d->cards[i] = deckRands[i].card_p;
     }
     }

void assert_full_deck(deck_t * d) {
  card_t card;
  int fulldeck = 1;
  for (suit_t i = SPADES; i < NUM_SUITS; i++) {
    for (unsigned j = 2; j <= VALUE_ACE; j++) {
      card.value = j;
      card.suit = i;
      int contains = deck_contains(d, card);
      if (contains == 0) {
	printf("deck is missing %c%c\n",value_letter(card), suit_letter(card));
	fulldeck = 0;
      }
    }
  }
  assert(fulldeck);
}

 void add_card_to(deck_t * deck, card_t c) {
   deck->n_cards++;
   deck->cards = realloc(deck->cards, deck->n_cards * sizeof(card_t*));
   deck->cards[deck->n_cards-1] = malloc(sizeof(card_t));
   *deck->cards[deck->n_cards-1] = c;
 }

 card_t * add_empty_card(deck_t * deck) {
   card_t empty;
   empty.value = 0;
   empty.suit = 0;
   add_card_to(deck, empty);
   return deck->cards[deck->n_cards-1];
 }

 deck_t * make_deck_exclude(deck_t * excluded_cards) {
   deck_t * builtDeck = malloc(sizeof(deck_t));
   builtDeck->cards = NULL;
   builtDeck->n_cards = 0;
   card_t card;
   for (size_t i = 0; i < 52; i++) {
     card = card_from_num(i);
     if (deck_contains(excluded_cards, card) == 0) {
       add_card_to(builtDeck, card);
     }
   }
   return builtDeck;
 }
 deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) {
   deck_t * exclusionDeck = malloc(sizeof(deck_t));
   exclusionDeck->cards = NULL;
   exclusionDeck->n_cards = 0;
   card_t exclusionCard;
   for (size_t i = 0; i < n_hands; i++) {
     for (size_t j = 0; j < hands[i]->n_cards; j++) {
       exclusionCard = *(hands[i]->cards[j]);
       if (deck_contains(exclusionDeck, exclusionCard) == 0) {
	 add_card_to(exclusionDeck, exclusionCard);
       }
     }
   }
   deck_t * remainingDeck = make_deck_exclude(exclusionDeck);
   free_deck(exclusionDeck);
   return remainingDeck;
 }

 void free_deck(deck_t * deck) {
   for (size_t i = 0; i < deck->n_cards; i++) {
     free(deck->cards[i]);
   }
   free(deck->cards);
   free(deck);
 }
     
