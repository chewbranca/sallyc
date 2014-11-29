#include <stdio.h>

#define MAX_LINE 1000 /* maximum input line size */

int trimmed_getline(char line[], int max_line);

/* trim trailing whitespace and empty lines */
int main() {
  int len;             /* current line length */
  char line[MAX_LINE]; /* current input line */

  while ((len = trimmed_getline(line, MAX_LINE)) > 0) {
    if (len > 1) {
      printf("%s", line);
    }
  }
}

/* get trimmed line with trailing whitespace removed */
int trimmed_getline(char s[], int lim) {
  int c, i, l;

  for (i=0, l=0;(c=getchar()) != EOF && c != '\n'; i++) {
    if (i < lim-1) {
      s[i] = c;
      if (c != ' ' && c != '\t') {
        l = i;
      }
    }
  }
  if (i > l+1) {
    i = l;
  }
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}
