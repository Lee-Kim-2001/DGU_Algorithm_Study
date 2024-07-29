#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 50001
#define MIN_HEAP_SIZE 50001

int max_heap[MAX_HEAP_SIZE], min_heap[MIN_HEAP_SIZE];
int max_heap_size = 0, min_heap_size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heap_push(int value) {
    max_heap[++max_heap_size] = value;
    int child = max_heap_size;
    int parent = child / 2;

    while (parent >= 1 && max_heap[parent] < max_heap[child]) {
        swap(&max_heap[parent], &max_heap[child]);
        child = parent;
        parent = child / 2;
    }
}

int max_heap_pop() {
    int root = max_heap[1];
    max_heap[1] = max_heap[max_heap_size--];
    int parent = 1;
    int child = parent * 2;

    while (child <= max_heap_size) {
        if (child + 1 <= max_heap_size && max_heap[child] < max_heap[child + 1]) {
            child++;
        }
        if (max_heap[parent] >= max_heap[child]) break;
        swap(&max_heap[parent], &max_heap[child]);
        parent = child;
        child = parent * 2;
    }
    return root;
}

void min_heap_push(int value) {
    min_heap[++min_heap_size] = value;
    int child = min_heap_size;
    int parent = child / 2;

    while (parent >= 1 && min_heap[parent] > min_heap[child]) {
        swap(&min_heap[parent], &min_heap[child]);
        child = parent;
        parent = child / 2;
    }
}

int min_heap_pop() {
    int root = min_heap[1];
    min_heap[1] = min_heap[min_heap_size--];
    int parent = 1;
    int child = parent * 2;

    while (child <= min_heap_size) {
        if (child + 1 <= min_heap_size && min_heap[child] > min_heap[child + 1]) {
            child++;
        }
        if (min_heap[parent] <= min_heap[child]) break;
        swap(&min_heap[parent], &min_heap[child]);
        parent = child;
        child = parent * 2;
    }
    return root;
}

int main(void) {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int current_value;
        scanf("%d", &current_value);

        if (max_heap_size == 0 || current_value <= max_heap[1]) {
            max_heap_push(current_value);
        } else {
            min_heap_push(current_value);
        }

        if (max_heap_size > min_heap_size + 1) {
            min_heap_push(max_heap_pop());
        } else if (min_heap_size > max_heap_size) {
            max_heap_push(min_heap_pop());
        }

        printf("%d\n", max_heap[1]);
    }

    return 0;
}
