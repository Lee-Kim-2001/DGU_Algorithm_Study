#include <stdio.h>
#include <stdlib.h>

int main() {
  int num, i, j, set;

  scanf("%d", &num);

  int *list = (int *)malloc(sizeof(int) * num);

  for(i = 0; i < num; i++) {
    scanf("%d", &list[i]);
  }

  for(i = 0; i < num; i++) {
    for(j = 0; j < num - i - 1; j++) {
      if(list[j] > list[j + 1]) {
        set = list[j];
        list[j] = list[j + 1];
        list[j + 1] = set;
      }
    }
  }

  for(i = 0; i < num; i++) {
    printf("%d\n", list[i]);
  }

  return 0;
}
