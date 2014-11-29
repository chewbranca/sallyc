#include <stdio.h>

/* count number of lines in put */
int main() {
  int c, nl;

  nl = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n')
      ++nl;
  printf("NL: %d\n", nl);
}
