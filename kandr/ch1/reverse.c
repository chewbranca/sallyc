#include <stdio.h>

#define MAX_LINE 1000 /* maximum input line size */

int mygetline(char line[], int maxline);
void print_reverse(char line[], int len);

/* trim trailing whitespace and empty lines */
int main() {
  int len;             /* current line length */
  char line[MAX_LINE]; /* current input line */

  while ((len = mygetline(line, MAX_LINE)) > 0) {
    print_reverse(line, len);
  }
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim) {
  int c, i;

  for (i=0;(c=getchar()) != EOF && c != '\n'; i++) {
    if (i < lim-1)
      s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}

/* print a line in verse */
void print_reverse(char line[], int len) {
  int i;

  for (i = len-1; i >= 0; i--) {
    putchar(line[i]);
  }
}
