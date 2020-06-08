CFLAGS=-ggdb3 -Wall -Werror -pedantic -std=gnu99
GIVEN_OBJS=eval-c4.o  future.o  input.o  main.o
MY_OBJS=cards.o deck.o eval.o

test-deck: deck.o test-deck.o cards.o
	gcc -o test-deck -ggdb3 deck.o test-deck.o cards.o
clean:
	rm test poker cards.o my-test-main.o *~
