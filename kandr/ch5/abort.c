#include <stdlib.h>

int foo();

int main() {
  foo();
}

int foo() {
  abort();
  return 1;
}
