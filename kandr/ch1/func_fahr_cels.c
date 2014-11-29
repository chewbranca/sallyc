#include <stdio.h>

double fahr_to_cels(int fahr);
double cels_to_fahr(int celsius);

#define MAX_TEMP 300
#define STEP 20

int main() {
  int fahr; int celsius;

  printf("Converting fahr to celsius:\n");
  for (fahr = 0; fahr <= MAX_TEMP; fahr = fahr + STEP)
    printf("%3d %6.1f\n", fahr, fahr_to_cels(fahr));

  printf("\nConverting celsius to fahr:\n");
  for (celsius = 0; celsius <= MAX_TEMP; celsius = celsius + STEP)
    printf("%3d %6.1f\n", celsius, cels_to_fahr(celsius));
}

double fahr_to_cels(int fahr) {
  return (5.0/9.0) * (fahr-32);
}

double cels_to_fahr(int celsius) {
  return (9.0 * celsius / 5.0) + 32;
}
