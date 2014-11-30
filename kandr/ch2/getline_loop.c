#include <stdio.h>

int main() {
  int i = 0;
  int lim = 1000;
  int c = 0;
  char s[lim];

  while(i < lim-1) {
    c = getchar();
    if (c == '\n') {
      break;
    } else if (c == EOF) {
      break;
    } else {
      s[i] = c;
      i++;
    }
  }

  printf("Line is: %s\n", s);
}
