#include <stdio.h>

void printit(int * arr, int n);

int main(int argc, char * argv[]) {
  printit({1,2,3,4,5}, 5);
}

void printit(int * arr, int n) {
  int i;

  printf("Printing arr: ");
  for (i = 0; i < n; i++) {
    printf("%d", arr[i]);
  }
  printf("\n");
}
