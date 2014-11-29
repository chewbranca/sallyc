#include <stdio.h>

#define MAX_LINE 1000 /* maximum input line size */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);
void maybe_print_80(char line[], int len);


/* print longest input line */
int main() {
  int len;                 /* current line length */
  int max;                 /* maximum current length seen so far */
  char line[MAX_LINE];     /* current input line */
  char longest[MAX_LINE];  /* longest line saved here */

  max = 0;
  while ((len = mygetline(line, MAX_LINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
    maybe_print_80(line, len);
  }
  if (max > 0) {     /* there was a line */
    printf("Longest line[%d]: %s", max, longest);
  }
  return 0;
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i = 0;

  while((to[i] = from[i]) != '\0') {
    i++;
  }
}

void maybe_print_80(char line[], int len) {
  if (len > 80) {
    printf("Line longer than 80[%d]: %s", len, line);
  }
}
