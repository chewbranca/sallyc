#include <stdio.h>

#define IN 1        /* inside a word */
#define OUT 0       /* outside a word */
#define MAX_WORD 20 /* longest expected word */

/* display histogram of lengths of words in input */
int main() {
  int c, i, j, wl, nw, state, max;
  int nword[MAX_WORD];

  for (i = 0; i < MAX_WORD; ++i)
    nword[i] = 0;

  state = OUT;
  wl = nw = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (wl > MAX_WORD) {
        printf("\n***ERROR*** TOO MANY CHARS: %d\n", wl);
      } else if (wl > 0) {
        nword[wl-1] = nword[wl-1] + 1;
      }
      wl = 0;
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++wl;
      ++nw;
    } else {
      ++wl;
    }
  }

  if (state == IN)
    nword[wl-1]++;

  printf("Horizontal histogram of %d word lengths::\n", nw);
  for (i = 0; i < MAX_WORD; ++i) {
    printf("WORD[%d]: ", i+1);
    for (j = 0; j < nword[i]; ++j)
      putchar('.');
    putchar('\n');
  }

  printf("\n\nVeritcal histogram of %d word lengths::\n", nw);
  for (i = 0, max = 0; i < MAX_WORD; ++i)
    if (nword[i] > max)
      max = nword[i];

  for (i = max; i > 0; --i) {
    for (j = 0; j < MAX_WORD; ++j) {
      putchar(' ');
      putchar(' ');
      if (nword[j] >= i)
        putchar('.');
      else
        putchar(' ');
    }
    putchar('\n');
  }

  for (i = 0; i < MAX_WORD; ++i)
    printf("===");
  putchar('\n');

  for (i = 0; i < MAX_WORD; ++i)
    printf("%3d", i+1);
  putchar('\n');
}
