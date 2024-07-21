#include <stdio.h>
#include <string.h>

int main(void) {
  int T, count, left_count = 0, yes_no_flag;
  char stack[51];

  scanf("%d", &T);

  for(int i = 0; i < T; i++) {
    scanf("%s", stack);
    count = strlen(stack);
    left_count = 0;
    yes_no_flag = 1;
    for(int j = 0; j < count; j++) {
      if(stack[j] == '(') 
        left_count++;
      
      else if(stack[j] == ')' && left_count == 0) {
        yes_no_flag = 0;
        break;
      }
      else if(stack[j] == ')' && left_count > 0)
        left_count--;
    }
    if(yes_no_flag && left_count == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  
  return 0;
}
