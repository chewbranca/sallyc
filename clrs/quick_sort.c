#include <stdio.h>

#include "sort.h"


void quick_sort(int* unsorted, int r);
void quick_sort_int(int* unsorted, int p, int r);
int partition(int* unsorted, int p, int r);


int main(int argc, char* argv[]) {
  int nums[] = {5, 2, 4, 7, 1, 3, 2, 6};
  int n = NELEMS(nums);
  quick_sort(nums, n-1);
  print_int_array("Sorted nums:  ", nums, n);
}


int partition(int* unsorted, int p, int r) {
  int x = unsorted[r];
  int i, j, tmp;

  for (i = p-1, j = p; j < r; j++) {
    if (unsorted[j] <= x) {
      i++;
      tmp = unsorted[i];
      unsorted[i] = unsorted[j];
      unsorted[j] = tmp;
    }
  }

  i++;
  tmp = unsorted[i];
  unsorted[i] = unsorted[r];
  unsorted[r] = tmp;

  return i;
}

void quick_sort(int* unsorted, int r) {
  quick_sort_int(unsorted, 0, r);
}


void quick_sort_int(int* unsorted, int p, int r) {
  int q;

  if (p < r) {
    q = partition(unsorted, p, r);
    quick_sort_int(unsorted, p, q-1);
    quick_sort_int(unsorted, q+1, r);
  }
}
