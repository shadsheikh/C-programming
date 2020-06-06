#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


int main(void) {
  card_t c1,c2,c3;
  c1.value = 9;
  c1.suit = SPADES;
  c2.value =1;
  c2.suit = SPADES;
  c3.value = VALUE_KING;
  c3.suit = NUM_SUITS;
  
  assert_card_valid(c1);
  assert_card_valid(c2);
  assert_card_valid(c3);

  return EXIT_SUCCESS;
}
