#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> 

int main()
{
  int n, m, a;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &a);

  long long num_of_flagstones = ceil(((double) n) / a) * ceil(((double) m) / a);
  printf ("%lld", num_of_flagstones);
  return 0;
}