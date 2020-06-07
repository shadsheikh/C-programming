#include <stdlib.h>
#include <stdio.h>

void rotate(char matrix[10][10]) {
  char tempMat[10][10];


  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tempMat[j][9-i] = matrix[i][j];
    }
  }



  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      matrix[i][j] = tempMat[i][j];
    }
  }


  return;
}

    
