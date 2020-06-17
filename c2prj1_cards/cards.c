#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"
#include <stdbool.h>

bool is_empty_card(card_t * c) {
    if(c == NULL){
      return false;
    }
    return (c->value == EMPTY_CARD_VALUE) && (c->suit == EMPTY_CARD_SUIT);
  }
  
void assert_card_valid(card_t c) {
  assert(c.value>=2 &&c.value <= VALUE_ACE);
  assert(c.suit >= SPADES && c.suit <= CLUBS );
  }

const char * ranking_to_string(hand_ranking_t r) {
 

  switch (r) {
  case STRAIGHT_FLUSH:    return "STRAIGHT_FLUSH";  break;  
  case FOUR_OF_A_KIND:    return "FOUR_OF_A_KIND";  break;
  case FULL_HOUSE:        return "FULL_HOUSE";      break;
  case FLUSH:             return "FLUSH";           break;
  case STRAIGHT:          return "STRAIGHT";        break;
  case THREE_OF_A_KIND:   return "THREE_OF_A_KIND" ;break;
  case TWO_PAIR:          return "TWO_PAIR";        break;
  case PAIR:              return "PAIR";            break;
  case NOTHING:           return "NOTHING";         break;
  default:                return "";        
   }
}

char value_letter(card_t c) {
  char out;
    switch (c.value) {
    case (10):out='0'; break;
    case (2) :out='2'; break;
    case (3) :out='3'; break;
    case (4) :out='4'; break;
    case (5) :out='5'; break;
    case (6) :out='6'; break;
    case (7) :out='7'; break;
    case (8) :out='8'; break;
    case (9) :out='9'; break;
    case VALUE_JACK  :out = 74 ;break;
    case VALUE_QUEEN :out = 81 ;break;
    case VALUE_KING  :out = 75 ;break;
    case VALUE_ACE   :out = 65 ;break;
    default          :out = 0;
    }
    return out;
}

char suit_letter(card_t c) {
  switch(c.suit){
  case CLUBS:     return 'c' ;   break;
  case SPADES:    return 's' ;   break;
  case HEARTS:    return 'h' ;   break;
  case DIAMONDS:  return 'd' ;   break;
  default :     return 0;
  }
  return 0;

  }

void print_card(card_t c) {
 char value  = value_letter(c);
  printf("%c" ,value);
 char suit  = suit_letter(c);
  printf("%c" ,suit);
  
}

card_t card_from_letters(char value_let, char suit_let) {
   card_t temp;
 switch (value_let) {
 case '2': temp.value =2;          ; break;
 case '3': temp.value =3;          ; break;
 case '4': temp.value =4;          ; break;
 case '5': temp.value =5;          ; break;
 case '6': temp.value =6;          ; break;
 case '7': temp.value =7;          ; break;
 case '8': temp.value =8;          ; break;
 case '9': temp.value =9;          ; break;
 case '0': temp.value=10;        ; break;
 case('J'):temp.value =VALUE_JACK  ; break;
 case('K'):temp.value =VALUE_KING  ; break;
 case('Q'):temp.value =VALUE_QUEEN ; break;
 case('A'):temp.value =VALUE_ACE   ; break;
 }

switch (suit_let) {
   case 's' : temp.suit = SPADES   ; break;
   case 'c' : temp.suit = CLUBS    ; break;
   case 'd' : temp.suit = DIAMONDS ; break;
   case 'h' : temp.suit = HEARTS   ; break;
   }
     return temp;

}

card_t card_from_num(unsigned c) {
  card_t temp;
  
 if (c>=0&&c<=12){
    temp.suit = HEARTS;
  }

  else if (c>=13&&c<=25){
    temp.suit = DIAMONDS;
  }
 
 else if(c>=26&&c<=38){
    temp.suit = SPADES;
  }

 else if (c>=39&&c<=51){
    temp.suit = CLUBS;
  }
  int val = c%13;

  switch (val) {
  case 0: temp.value = VALUE_ACE; break;
  case 1: temp.value = VALUE_KING; break;
  case 11:temp.value = VALUE_QUEEN; break;
  case 12:temp.value = VALUE_JACK ; break;
  default :temp.value = val; break;
      }
    return temp;
}
