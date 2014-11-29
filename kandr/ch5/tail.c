#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000 /* max line length */

int readlines(char *lines[], int numlines);
int mygetline(char line[], int max);

int main(int argc, char *argv[]) {
  char line[MAXLINE];
  long lineno = 0;
  int i, n;

  /* if (argc != 3 || argv[1] != "-n") { */
  if (argc != 3) {
    printf("Usage: tail -n N\n");
  } else if (argv[1][0] != '-' || argv[1][1] != 'n') {
    printf("Usage: tail -n N\n");
  } else {
    n = atoi(argv[2]);
    char lines[n];
    readlines(lines, n);
  }
}

int readlines(char *lines[], int numlines) {
  int i = 0;
  int min = 0;
  int j;
  int len = 0;
  char line[MAXLINE];
  long lineno = 0;

  while ((len = mygetline(line, MAXLINE)) > 0) {
    lineno++;
    i = (i+1) % numlines;
    lines[i] = malloc(len);
    strcpy(lines[i], line);
  }

  /* min = lineno < numlines ? lineno : numlines; */

  printf("Found lines %d || %d\n", lineno, numlines);
  if (lineno <= numlines) {
    for (i = 0; i < lineno; i++) {
      printf("%s", lines[i]);
    }
  } else {
    j = numlines;
    while (j-- > 0) {
      printf("***i is[%d]: (((%s)))\n", i, lines[i]);
      printf("%s", lines[++i % numlines]);
    }
  }

  return lineno;
}

int mygetline(char s[], int lim) {
  int c, i;

  i = 0;
  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}
