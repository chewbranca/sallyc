#include <stdio.h>

int main() {
  char c = 0;
  int i = 0;
  short s = 0;
  long l = 0;

  while (++c > 0)
    ;
  --c;
  while (++i > 0)
    ;
  ++i;

  printf("Max char: %d\nMax int: %d\n", c, i);
}
