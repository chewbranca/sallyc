#include <stdio.h>

#define BLANK ' '

int main() {
  int c, p;

  while ((c = getchar()) != EOF) {
    if (c == BLANK && p != BLANK)
      putchar(c);
    if (c != BLANK)
      putchar(c);
    p = c;
  }
}
