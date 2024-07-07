#include <stdio.h>

int main() {
  int m, d;
  char *dw[8] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  scanf("%d %d", &m, &d);

  switch(m) {
    case 2 :
      d += 31;
      break;
    case 3 :
      d += 59;
      break;
    case 4 :
      d += 90;
      break;
    case 5 :
      d += 120;
      break;
    case 6 :
      d += 151;
      break;
    case 7 :
      d += 181;
      break;
    case 8 :
      d += 212;
      break;
    case 9 :
      d += 243;
      break;
    case 10 :
      d += 273;
      break;
    case 11 :
      d += 304;
      break;
    case 12 :
      d += 334;
      break;
  }

  d = (d - 1) % 7;

  printf("%s", dw[d]);

  return 0;
}
