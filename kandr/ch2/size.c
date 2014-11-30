#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
  signed int i, min, max;
   
   i = min = max = 0;
   while (++i) {
     if (i > max)
       max = i;
        
      if (i < min)
        min = i;
   }
   printf ("min: %d\n", min);
   printf ("Max: %d\n", max);
   printf ("Size: %d byte(s)\n", sizeof(i));
}
