#include <stdio.h>
#include <string.h>


int main(void) {
  char str[31], stack[31];

  int data = 0, pow = 1, big_box = 0, small_box = 0, last_flag = 0, stack_count = 0;

  scanf("%s", str);

  for(int i = 0; i < strlen(str); i++) {
    if(str[i] == '(') {
      pow *= 2;
      last_flag = 0;
      small_box++;
      stack[stack_count] = '(';
      stack_count++;
    }

    else if(str[i] == '[' ) {
      pow *= 3;
      last_flag = 0;
      big_box++;
      stack[stack_count] = '[';
      stack_count++;
    }

    else if(small_box == 0 && str[i] == ')') {
      data = 0;
      break;
    }

    else if(big_box == 0 && str[i] == ']') {
      data = 0;
      break;
    }

    else if(small_box != 0 && str[i] == ')') {
      if(stack[stack_count - 1] != '(') {
        data = 0;
        break;
      }
      
      else if(!last_flag) {
        data += pow;
        last_flag = 1;
      }
      pow /= 2;
      small_box--;
      stack_count--;
    }

    else if(big_box != 0 && str[i] == ']') {
      if(stack[stack_count - 1] != '[') {
        data = 0;
        break;
      }
      
      else if(!last_flag) {
        data += pow;
        last_flag = 1;
      }
      pow /= 3;
      big_box--;
      stack_count--;
    }
  }

  if(small_box == 0 && big_box == 0)
    printf("%d", data);
  else
    printf("0");
  return 0;
}
