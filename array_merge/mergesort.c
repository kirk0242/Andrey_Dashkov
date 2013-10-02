#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "mergesort.h"
/**/

bool needsSorting(int rangeSize) {
  return rangeSize >= 2;
}





void mergeRanges(int values[], int startIndex, int midPoint, int endIndex) {
  int rangeSize, firstIndex, secondIndex, copyIndex, i;
  rangeSize = endIndex - startIndex;
  char* destination;
  destination = calloc(rangeSize, sizeof(int));
  firstIndex = startIndex;
  secondIndex = midPoint;
  copyIndex = 0;
  while (firstIndex < midPoint && secondIndex < endIndex){
    if (values[firstIndex] < values[secondIndex]) {
      destination[copyIndex] = values[firstIndex];
      ++firstIndex;
    } else {
      destination[copyIndex] = values[secondIndex];
      ++secondIndex;
    }
    ++copyIndex;
  }
  while (firstIndex < midPoint) {
    destination[copyIndex] = values[firstIndex];
    ++copyIndex;
    ++firstIndex;
  }
  while (secondIndex < endIndex) {
    destination[copyIndex] = values[secondIndex];
    ++copyIndex;
    ++secondIndex;
  }
  for (i = 0; i < rangeSize; i++){
    values[i + startIndex] = destination[i];
  }
  free(destination);
}



void mergesortRange(int values[], int startIndex, int endIndex){
  int rangeSize;
  rangeSize = endIndex - startIndex;
  if(needsSorting(rangeSize)){
    int midPoint;
    midPoint = (startIndex + endIndex) / 2;
    mergesortRange(values, startIndex, midPoint);
    mergesortRange(values, midPoint, endIndex);
    mergeRanges(values, startIndex, midPoint, endIndex);
  }
}

void mergesort(int size, int values[]){
  mergesortRange(values, 0, size);
}
