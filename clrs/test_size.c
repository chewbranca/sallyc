#include <stdio.h>

void testit(int * l);

int main(int argc, char * argv[]) {
  int l[] = {1,2,3};

  printf("SIZE * / SIZE 0: %lu/%lu\n", sizeof(l), sizeof(l[0]));

  testit(l);
}

void testit(int * l) {
  printf("SIZE * / SIZE 0: %lu/%lu\n", sizeof(l), sizeof(l[0]));
}

/*
output is:
./test_size
SIZE * / SIZE 0: 12/4
SIZE * / SIZE 0: 8/4
wtf?!?!
*/
