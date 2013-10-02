#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "array_merge.h"
#include "mergesort.c"



int* array_merge(int num_arrays, int* sizes, int** values){

  int* empty[] = { 0 };
  int i, j, max_value, true_count;
  bool* unique;
  int* count;
  true_count = 0;
  max_value = 0;
  
  for(i = 0; i < num_arrays; i++){
    mergesort(sizes[i], values[i]);
    if(values[i][sizes[i]] > max_value){
      max_value = values[i][sizes[i]];
    }
  }
  unique = calloc(max_value, sizeof(bool));
  // Each array
  for(i = 0; i < max_value; i++){
    unique[i] = false;
  }
 
  for(i = 0; i < num_arrays; i++){
    for(j = 0; j < sizes[i] + 1; j++){
      if(unique[values[i][j]] == false){
        unique[values[i][j]] = true;
	true_count++;
      }
    }
  }

  count = calloc(true_count + 1, sizeof(int));
  count[0] = true_count;
  j = 1;
  for(i = 0; i < max_value + 1; i++){
    if(unique[i] == true){
      count[j] = i;
      j++;
    }
  }
  if(true_count == 0){
    return empty;
  } else {
    return count;
  }
}

