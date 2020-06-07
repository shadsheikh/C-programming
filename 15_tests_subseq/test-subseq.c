#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n);

void main(void) {


  int arrays[][10] = {{1, 2, 3, 1, 2, 3, 1, 2, 3, 1},
		      {1, 2, 1, 3, 5, 7, 2, 4, 6, 9},
		      {1, 3, 6, 8, 1, 2, 4, 1,99, 0},
		      {1, 3, 6, 8, 3, 2, 3, 4,10,99},
		      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		      {10,9, 8, 7, 6, 5, 4, 3, 2, 1},
		      {-3,-2,-1,0, 1, 2, 3, 0, 0, 0},
		      {0, 1, 2,-3,-4,-5, 0, 0, 0, 0}
  };

  int answers[] = {3,4,4,5,1,1,7,3};
  int n = 8;


  for(int i = 0; i < n; i++) {

    if (maxSeq(arrays[i],10 != answers[i]) {

	printf("failed array %d\n",i);
	exit(EXIT_FAILURE);
      }
      }


    int emptyArray[] = {};
    if (maxSeq(emptyArray,0) != 0) {
      printf("failed emptyArray\n");
      exit(EXIT_FAILURE);
    }

    printf("pass\n");

    exit(EXIT_SUCCESS);
  }
