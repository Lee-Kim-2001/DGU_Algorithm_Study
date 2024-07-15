#include <stdio.h>
#include <stdlib.h>

int compare(const int *a, const int *b) {
    return (*(int *)a - *(int *)b);
}

int _2search(int *arr, int N, int C, int min_dist) {
    int count = 1;
    int last_position = arr[0];

    for (int i = 1; i < N; i++) {
        if (arr[i] - last_position >= min_dist) {
            count++;
            last_position = arr[i];
        }
    }

    return count >= C;
}

int main() {
    int N, C;
    scanf("%d %d", &N, &C);

    int *arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    int low = 1;
    int high = arr[N - 1] - arr[0];
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (_2search(arr, N, C, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", result);

    free(arr);
    
    return 0;
}
