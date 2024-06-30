#include<stdio.h>

int main() {
    int a, i, pos = 1;
    scanf("%d", &a);
    
    for(i = 1; i <= a ; i++) {
        pos *= i;
    }
    printf("%d", pos);
}
