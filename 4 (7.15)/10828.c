#include <stdio.h>
#include <string.h>

int stack[10000], position = 0;

void push(int num) {
  position++;
  stack[position] = num;
}

void pop() {
  if (position == 0) {
    printf("-1\n");
  }

  else {
    printf("%d\n", stack[position]);
    position--;
  }
}

void size() {
  printf("%d\n", position);
}

void empty() {
  if (position == 0)
    printf("1\n");
  else
    printf("0\n");
}

void top() {
  if (position == 0)
    printf("-1\n");
  else
    printf("%d\n", stack[position]);
}

int main() {
  char command[6];
  int time, data;

  scanf("%d", &time);

  for (int i = 0; i < time; i++) {
    scanf("%s", command);

    if (strcmp(command, "push") == 0) {
      scanf("%d", &data);
      push(data);
    }

    else if (strcmp(command, "pop") == 0) {
      pop();
    }

    else if (strcmp(command, "size") == 0) {
      size();
    }

    else if (strcmp(command, "empty") == 0) {
      empty();

    }

    else if (strcmp(command, "top") == 0) {
      top();
    }
  }

  return 0;
}
