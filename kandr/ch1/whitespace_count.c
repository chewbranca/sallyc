#include <stdio.h>

/* count number of blanks, tabs and newlines */
int main() {
  long nb, nt, nl;
  int c;

  nb = 0;      /* number of blanks */
  nt = 0;      /* number of tabs */
  nl = 0;      /* number of lines */

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++nb;
    if (c == '\t')
      ++nt;
    if (c == '\n')
      ++nl;
  }
  printf("NB: %ld\nNT: %ld\nNL: %ld\n", nb, nt, nl);
}
