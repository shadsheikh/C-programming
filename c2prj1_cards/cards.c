#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  int v;
  int vvalidity = 0;
  for (v=2;v<=VALUE_ACE;v++) {
    if (c.value ==v) {
      vvalidity = 1;
    
    break;
  }
  
}

  assert(vvalidity == 1);
int s;
int svalidity = 0;
for(s=0;s<NUM_SUITS;s++) {
    if(c.suit == s) {
      svalidity = 1;
      break;
    }
  }
  assert(svalidity == 1);
 }

const char * ranking_to_string(hand_ranking_t r) {
 

  switch (r) {
  case STRAIGHT_FLUSH:
    return "STRAIGHT_FLUSH";
      case FOUR_OF_A_KIND:
    return " FOUR_OF_A_KIND";
      case FULL_HOUSE:
    return " FULL_HOUSE";
      case FLUSH:
    return "FLUSH";
      case STRAIGHT:
    return "STRAIGHT";
      case THREE_OF_A_KIND:
    return " THREE_OF_A_KIND ";
      case TWO_PAIR:
    return "TWO_PAIR";
      case PAIR:
    return "PAIR";
      case NOTHING:
    return "NOTHING";
      default:
    return "INVALID";
  }
}

char value_letter(card_t c) {
  char x;
  if((c.value >= 2)&&(c.value<=9)) {
    x='0' +c.value;
  }
  else{
    switch (c.value) {
    case 10:         x='0'; break;
    case VALUE_JACK: x='J'; break;
    case VALUE_QUEEN:x='Q'; break;
    case VALUE_KING: x='K'; break;
    case VALUE_ACE:  x='A'; break;
    default:         x='X'; break;
    }
  }
  return x;
}

char suit_letter(card_t c) {
  char x;
  switch(c.suit){
  case SPADES:    x= 's' ;   break;
  case HEARTS:     x= 'h' ;   break;
  case DIAMONDS:  x= 'd' ;   break;
  case CLUBS:     x= 'c' ;   break;
  default :       x= 'x' ;   break;
  }
  return x;

  }

void print_card(card_t c) {
  char value = value_letter(c);
  char suit  = suit_letter(c);
  printf("%c%c" , value,suit);
  
}

card_t card_from_letters(char value_let, char suit_let) {
   card_t temp;
   if(value_let >= '2' && value_let <= '9') {
     temp.value = value_let - '0';
   }

   else if (value_let == '0' || value_let == 'J' || value_let == 'Q'||value_let == 'K'||value_let == 'A') {
     switch (value_let) {
 case '0': temp.value =10;          ; break;
 case 'J': temp.value =VALUE_JACK   ; break;
 case 'Q': temp.value =VALUE_QUEEN  ; break;
 case 'K': temp.value =VALUE_KING   ; break;
 case 'A': temp.value =VALUE_ACE    ; break;
 default : temp.value = 0;
}
}

   else {
     printf("invalid value \n");
     exit (EXIT_FAILURE);
   }

   switch (suit_let) {
   case 's' : temp.suit = SPADES ; break;
   case 'h' : temp.suit = HEARTS ; break;
   case 'd' : temp.suit = DIAMONDS ; break;
   case 'c' : temp.suit = CLUBS ; break;
   default : exit(EXIT_FAILURE);
   }
   return temp;
}


card_t card_from_num(unsigned c) {
  card_t temp;
  unsigned suitNum = c /13;
  unsigned valNum = c % 13;
  switch (suitNum) {
  case 0: temp.suit = SPADES; break;
  case 1: temp.suit = HEARTS; break;
  case 2: temp.suit = DIAMONDS; break;
  case 3: temp.suit = CLUBS ; break;
  default : exit(EXIT_FAILURE);
      }
  temp.value = valNum + 2;
    return temp;
}
