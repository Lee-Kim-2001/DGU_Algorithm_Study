#include <stdio.h>

int main() {
  int a, b, v;
  int d;

  scanf("%d %d %d", &a, &b, &v);

    d = (v - b) / (a - b);

  if ((v - b) % (a - b) != 0) {
    d = (v - b) / (a - b) + 1;
  }

  printf("%d\n", d);
}
