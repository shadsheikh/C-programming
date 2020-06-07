#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n) {

  size_t tempCounter = 1;
  size_t maxCount = 1;


  if (n < 1) {
    return 0;
  }

  for (size_t i= 0; i < n; i++) {

    if((i == n-1)&&(tempCounter > maxCount)) {
      maxCount = tempCounter;
    }
    else if (array[i+1] > array[i]) {

      tempCounter++;
    }
    else {


      if (tempCounter > maxCount) {
	maxCount = tempCounter;
      }

      tempCounter = 1;
   
    }
}

return maxCount;
}
