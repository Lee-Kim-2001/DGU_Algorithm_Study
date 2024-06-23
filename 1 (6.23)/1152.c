#include <stdio.h>
#include <string.h>

int main() {
  char str[1000001];
  char *word;
  int count = 0;

  scanf("%[^\n]s", &str);
  word = strtok(str, " ");

  while (word != NULL) {
    word = strtok(NULL, " ");
    count++;
  }
  printf("%d", count);

  return 0;
}
