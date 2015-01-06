#include <stdio.h>

#include "sort.h"

void print_int_array(char * msg, int * array, int length) {
  int i;

  printf("%s [", msg);
  for (i = 0; i < length; i++) {
    printf("%d, ", array[i]);
  }
  printf("]\n");
}
