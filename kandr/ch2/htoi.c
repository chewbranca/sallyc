#include <stdio.h>

int htoi(char s[]);

int main() {
  printf("123A is: %d\n", htoi("123A\0"));
  printf("0xFF is: %d\n", htoi("0xFF\0"));
  printf("0XBB is: %d\n", htoi("0xBB\0"));
  printf("0xGG is: %d\n", htoi("0xGG\0"));
}

int htoi(char s[]) {
  int n = 0;
  int i = 0;
  int v = 0;

  if (s[0] == '0') {
    if (s[1] == 'x' || s[1] == 'X') {
      i = 2;
    }
  }

  while (s[i] != '\0') {
    if (s[i] >= '0' && s[i] <= '9') {
      v = s[i] - '0';
    } else if (s[i] >= 'A' && s[i] <= 'F') {
      v = s[i] - 'A' + 10;
    } else {
      return -1;
    }
    n = n * 16 + v;
    i++;
  }

  return n;
}
