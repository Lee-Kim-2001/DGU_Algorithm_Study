#include <stdio.h>
#include <stdlib.h>

#define MAX_N 32001

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

Node* adj[MAX_N];
int in_degree[MAX_N];
int queue[MAX_N];
int front = 0, rear = 0;

void add_edge(int u, int v) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vertex = v;
    new_node->next = adj[u];
    adj[u] = new_node;
    in_degree[v]++;
}

void enqueue(int v) {
    queue[rear++] = v;
}

int dequeue() {
    return queue[front++];
}

int is_empty() {
    return front == rear;
}

void topological_sort(int N) {
    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) {
            enqueue(i);
        }
    }

    while (!is_empty()) {
        int u = dequeue();
        printf("%d ", u);

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            in_degree[v]--;
            if (in_degree[v] == 0) {
                enqueue(v);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        adj[i] = NULL;
        in_degree[i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        add_edge(A, B);
    }

    topological_sort(N);

    for (int i = 1; i <= N; i++) {
        Node* temp;
        while (adj[i] != NULL) {
            temp = adj[i];
            adj[i] = adj[i]->next;
            free(temp);
        }
    }

    return 0;
}
