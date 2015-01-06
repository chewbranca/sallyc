#include <limits.h>
#include <stdio.h>

#include "sort.h"

void merge_sort(int * unsorted, int r);
void merge_sort_(int * unsorted, int p, int r);
void merge(int * unsorted, int p, int q, int r);

int n;

int main(int argc, char *argv[]) {
  /* int nums[] = SAMPLE_NUMS; */
  /* int nums[] = {3,2,1,0}; */
  int nums[] = {5, 2, 4, 7, 1, 3, 2, 6};
  extern int n;
  n = NELEMS(nums);
  merge_sort(nums, n-1);
  print_int_array("Sorted nums:  ", nums, n);
}

// clrs 2.3
void merge_sort(int * unsorted, int r) {
  printf("SIZE * / SIZE 0: %lu/%lu\n", sizeof(unsorted), sizeof(unsorted[0]));
  printf("INITIAL NE: %lu\n", NELEMS(unsorted));
  printf("R IS: %d\n", r);
  merge_sort_(unsorted, 0, r);
}

void merge_sort_(int * unsorted, int p, int r) {
  char s[100];
  extern int n;
  sprintf(s, "P/Q/R :: %2.d/%2.d/%2.d\n", p, (p+r)/2, r);
  print_int_array(s, unsorted, n);
  int q;

  if (p < r) {
    q = (p + r) / 2;
    merge_sort_(unsorted, p, q);
    merge_sort_(unsorted, q+1, r);
    merge(unsorted, p, q, r);
  }
}

void merge(int * unsorted, int p, int q, int r) {
  char s[100];
  extern int n;
  sprintf(s, "MERGE -- P/Q/R :: %2.d/%2.d/%2.d\n", p, q, r);
  print_int_array(s, unsorted, n);
  int i, j, k;

  int n1 = q - p + 1; // +1 ??
  int n2 = r - q;

  int left[n1+1];
  int right[n2+1];

  printf("Left is[%d]: ", n1);
  for (i = 0; i < n1; i++) {
    left[i] = unsorted[p+i];
    printf("%d ", left[i]);
  }
  printf("\nRight is[%d]: ", n2);
  for (j = 0; j < n2; j++) {
    right[j] = unsorted[q+j+1];
    printf("%d ", right[j]);
  }
  printf("\n");

  left[n1] = INT_MAX;
  right[n2] = INT_MAX;

  for (i = 0, j = 0, k = p; k <= r; k++) {
    if (left[i] <= right[j]) {
      unsorted[k] = left[i++];
    } else {
      unsorted[k] = right[j++];
    }
  }
}

