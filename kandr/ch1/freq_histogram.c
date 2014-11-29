#include <stdio.h>

#define MAX_CHAR 128  /* ascii char boundary */

/* display frequency histogram of chars in input */
int main() {
  int c, i, j;
  int max = 0;
  int char_freq[MAX_CHAR];

  for (i = 0; i < MAX_CHAR; i++)
    char_freq[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c < MAX_CHAR) {
      char_freq[c]++;
    }
  }

  printf("Histogram of character frequencies:\n");
  for (i = 0; i < MAX_CHAR; i++) {
    if (char_freq[i] > 0) {
      printf("ASCII[%d]: ", i);
      for (j = 0; j < char_freq[i]; j++) {
        putchar('.');
      }
      putchar('\n');
    }
  }
}
