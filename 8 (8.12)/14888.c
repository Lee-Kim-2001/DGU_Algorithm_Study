#include <stdio.h>
#include <limits.h>

int N;
int A[11];
int op[4];
int max_value = INT_MIN;
int min_value = INT_MAX;

void dfs(int index, int current_value) {
    if (index == N) {
        if (current_value > max_value) max_value = current_value;
        if (current_value < min_value) min_value = current_value;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;

            if (i == 0) dfs(index + 1, current_value + A[index]);
            if (i == 1) dfs(index + 1, current_value - A[index]);
            if (i == 2) dfs(index + 1, current_value * A[index]);
            if (i == 3) dfs(index + 1, current_value / A[index]);

            op[i]++;
        }
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < 4; i++) {
        scanf("%d", &op[i]);
    }

    dfs(1, A[0]);

    printf("%d\n", max_value);
    printf("%d\n", min_value);

    return 0;
}
