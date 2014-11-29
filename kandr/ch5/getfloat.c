#include <ctype.h>
#include <stdio.h>

#include "getch.c"

int mygetfloat(double *pn);

int main(int argc, char *argv[]) {
  double flt = 0.0;
  double res = 0.0;

  res = mygetfloat(&flt);
  if (res == EOF || res > 0) {
    printf("Float value is: %f\n", flt);
  } else {
    printf("Invalid float\n");
  }
}

/* mygetfloat: get next float from input into *pn */
int mygetfloat(double *pn) {
  int c, sign, power;

  while (isspace(c = getch()))  /* skip whitespace */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);  /* it's not a number */
    return 0;
  }

  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();

  for (*pn = 0.0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + (c - '0');
  }

  if (c == '.') {
    for (power = 1, c = getch(); isdigit(c); c = getch()) {
      *pn = 10 * *pn + (c - '0');
      power = 10 * power;
    }
    *pn /= (double)power;
  }
  if (c != EOF) {
    ungetch(c);
  }
  return c;
}
