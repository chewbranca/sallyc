#include <stdio.h>

void foo(double *p);

int main() {
  double *p = NULL;
  foo(p);
}

void foo(double *p) {
  *p = 3.14;
}
