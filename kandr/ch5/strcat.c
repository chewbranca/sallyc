#include <stdio.h>

void mystrcat(char *t, char *s);

int main() {
  char s1[] = "blahBLAHblah";
  char s2[1000];
  char *s2p = &s2[0];
  int i, j;

  for (j = 0; s1[j] != '\0'; j++)
    ;

  for (i = 0; i < 4; i++) {
    mystrcat(s2p + i*j, s1);
  }

  printf("Final s2: %s\n", s2);
}

void mystrcat(char *t, char *s) {
  while((*t++ = *s++))
    ;
}
