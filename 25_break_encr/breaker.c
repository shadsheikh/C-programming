#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void frequencyOfChars(FILE * file,int frequencies[]{
    int currChar;
    while((currChar = fgetc(file)) != EOF){
      if(isalph(currChar)){
	currChar = tolower(currChar);
	currChar -= 'a';
	frequencies[currChar]++;
      }
    }
  }

  int calcKey(int frequencies[]){
    int maxIdx = 0;
    for(int i=0;i<26;i++){
      if(frequencies[i] > frequencies[maxIdx]){
	  maxIdx = i;
	}
	}

    int key = 0;

    if(maxIdx >= ('e' - 'e')){
      key = maxIdx - ('e'-'a');
    }
    else {
      key = (26-('e'-'a'))+maxIdx;
    }
    return key;
  }

  int main(int argc , char ** argv){
    if(argc != 2){
      fprintf(stderr,"Wrong number of commmand line arguments\n");
      return EXIT_FAILURE;
    }
    FILE * file = fopen(argv[1],"r");

    if(file == NULL){
      perror("File is not valid\n");
      return EXIT_FAILURE;
    }

    int frequencies[26] = {0};
    frequencyOfChars(file,frequencies);

    int key = calcKey(frequencies);

    printf("%d\n",key);

    if(fclose(file) != 0){
      perror("Failed to close the file\n");
      return EXIT_FAILURE;
    }
  }
