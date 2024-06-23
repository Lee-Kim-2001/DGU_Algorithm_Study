#include<stdio.h>
#include<stdlib.h>

int main() {
    int N, X, i;
    scanf("%d %d", &N, &X);
    int *A = (int*)malloc(sizeof(int) * N);
    for(i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for(i = 0; i < N; i++) {
        if( X > A[i])
            printf("%d ", A[i]);
    }
    return 0;
}
