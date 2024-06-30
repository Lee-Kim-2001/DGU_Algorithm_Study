#include <stdio.h>
#include <stdlib.h>

int main() {
  int num, i, j, count = 0, set;

  scanf("%d", &num);

  int *list = (int *)malloc(sizeof(int) * num);

  for (i = 0; i < num; i++) {
    scanf("%d", &list[i]);
  }

  for (i = 0; i < num; i++) {

    set = 0;

    for (j = 1; j <= list[i]; j++) {
      if (list[i] % j == 0)
        set++;
    }
    if(set == 2)
      count++;
  }
  printf("%d", count);
  return 0;
}
