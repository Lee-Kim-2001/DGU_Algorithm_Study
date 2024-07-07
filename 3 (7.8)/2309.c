#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[9], data, sum = 0, num1, num2;
  
  for(int i = 0; i < 9; i++) {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }

  sum -= 100;
  
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 8 - i; j++) {
      if(arr[j] >= arr[j+1]) {
        data = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = data;
      }
    }
  }
  
  for(int i = 0; i < 8; i++) {
    for(int j = 1; j < 9 - i; j++) {
      if(sum == arr[i] + arr[i+j]) {  
        num1 = i;
        num2 = i+j;
        break;
      }
    }
  }

  for(int i = 0; i < 9; i++) {
    if( i != num1 && i != num2 ) {
      printf("%d\n", arr[i]);
    }
  }
  
  return 0;
}
