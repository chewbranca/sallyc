#include <stdio.h>

#include "sort.h"

void bubble_sort(int *a, int l);

int main(int argc, char *argv[]) {
  int nums[] = {5, 2, 4, 7, 1, 3, 2, 6};
  int n = NELEMS(nums);
  bubble_sort(nums, n);
  print_int_array("Sorted nums:  ", nums, n);
}

void bubble_sort(int *a, int l) {
  int i, j, t;

  for (i = 0; i < l; i++) {
    for (j = l-1; j > i; j--) {
      if (a[j] < a[j-1]) {
        t = a[j-1];
        a[j-1] = a[j];
        a[j] = t;
      }
    }
  }
}
