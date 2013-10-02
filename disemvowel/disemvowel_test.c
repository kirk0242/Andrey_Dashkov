#include <stdarg.h>
#include <setjmp.h>
#include <stdlib.h>

#include "../include/cmockery.h"
#include "disemvowel.h"

/*Still has an outstanding memory leak.*/
void test_empty_str(void) {
  assert_string_equal("", disemvowel(""));
}

void test_no_vowels(void) {
  char *call;
  call = disemvowel("pqrst");
  assert_string_equal("pqrst", call);
  free(call);
}

void test_only_vowels(void) {
  char *call;
  call = disemvowel("aeiouAEIOUOIEAuoiea");
  assert_string_equal("", call);
  free(call);
}

void test_my_name(void) {
  char *call;
  call = disemvowel("Nicholas Freitag McPhee");
  assert_string_equal("Nchls Frtg McPh", call);
  free(call);
}

void test_punctuation(void) {
  char *call;
  call = disemvowel("An (Unexplained) Elephant!");
  assert_string_equal("n (nxplnd) lphnt!", call);
  free(call);
}

void test_long_string(void) {
  char* str;
  int size;
  int i;

  size = 50000;
  str = calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  assert_string_equal("xyz", disemvowel(str));

  free(str);
}

int main(int argc, char* argv[]) {
  UnitTest tests[] = {
    unit_test(test_empty_str),
    unit_test(test_no_vowels),
    unit_test(test_only_vowels),
    unit_test(test_my_name),
    unit_test(test_punctuation),
    unit_test(test_long_string)
  };
  return run_tests(tests);
}
