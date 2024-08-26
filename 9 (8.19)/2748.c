#include <stdio.h>

long pibonachi(long n, long a, long b) {
  if(!n)
    return a;
  else
    pibonachi(n-1, b, a+b);
}

int main(void) {
  long n;
  scanf("%ld", &n);
  printf("%ld", pibonachi(n, 0, 1));
  return 0;
}
