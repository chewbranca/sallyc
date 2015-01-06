#include <stdio.h>


#define NELEMS(x)  (sizeof(x) / sizeof(x[0]))

void insertion_sort(int * unsorted, unsigned length);
void print_int_array(char * msg, int * array, unsigned length);


int main(int argc, char *argv[]) {
  int nums[] = {7,2,5,1,8,4,3,2,9,0};
  unsigned n = NELEMS(nums);

  print_int_array("Initial nums: ", nums, n);
  insertion_sort(nums, n);
  print_int_array("Sorted nums:  ", nums, n);
}

;; clrs 2.1
void insertion_sort(int * unsorted, unsigned length) {
  int i, j, key;

  for (j = 1; j < length; j++) {
    key = unsorted[j];
    i = j - 1;

    while (i >= 0 && unsorted[i] > key) {
      unsorted[i+1] = unsorted[i];
      i--;
    }

    unsorted[i+1] = key;
  }
}

void print_int_array(char * msg, int * array, unsigned length) {
  int i;

  printf("%s", msg);
  for (i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
