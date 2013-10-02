#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "disemvowel.h"

char* disemvowel(char* str) {
  int i, j, len, index;
  char* bad_char;
  char* result;
  bool* failed;
  failed = false;

  len = strlen(str);
  result = calloc(len +1, sizeof(char));
  index = 0;

  bad_char = calloc(10, sizeof(char));
  bad_char[0] = 'A';
  bad_char[1] = 'E';
  bad_char[2] = 'I';
  bad_char[3] = 'O';
  bad_char[4] = 'U';
  bad_char[5] = 'a';
  bad_char[6] = 'e';
  bad_char[7] = 'i';
  bad_char[8] = 'o';
  bad_char[9] = 'u'; 
 
  
  for(i = 0; i < len + 1; i++){
    for(j = 0; j < 10; j++){
      if(str[i] == bad_char[j]){
	failed = true;
      }
    }
    if(failed == false){
      result[index] = str[i];
      index++;
    }
    failed = false;
  }
  free(bad_char);
  if(index == 0){
    return "";
  } else {
    return result;
  } 
}
 
 
  



 /*char *upper_case;
  char *lower_case;
  int i, j, len, index;
  len = 5;
  len = strlen(str); 
  char *result;
  index = 0;
  result = calloc(len+1, sizeof(char));
  
  upper_case = calloc(6, sizeof(char));
  upper_case[0] = 'A';
  upper_case[1] = 'E';
  upper_case[2] = 'I';
  upper_case[3] = 'O';
  upper_case[4] = 'U';
  lower_case = calloc(6, sizeof(char));
  lower_case[0] = 'a';
  lower_case[1] = 'e';
  lower_case[2] = 'i';
  lower_case[3] = 'o';
  lower_case[4] = 'u'; 

  

  for(i=0; i < len+1; i++){
    result[i] = str[i]
     for(j = 0; i < 6; j++){
      
       if(upper_case[j] == str[i]){
	break;
      } else if (lower_case[j] == str[i]){
	break;
      } else if (j == 5){ 
	result[index] = str[i];
	index += 1;
	}
  }
  return str;*/

 
