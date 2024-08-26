#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char expression[51];
    scanf("%s", expression);

    int result = 0;
    int temp = 0;
    int minus = 0;

    for (int i = 0; i <= strlen(expression); i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            temp = temp * 10 + (expression[i] - '0');
        }

        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '\0') {
            if (minus) {
                result -= temp;
            } else {
                result += temp;
            }

            temp = 0;

            if (expression[i] == '-') {
                minus = 1;
            }
        }
    }
    printf("%d\n", result);

    return 0;
}
