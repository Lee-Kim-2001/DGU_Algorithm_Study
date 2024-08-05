#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int vertex;
    int cost;
    struct Node* next;
} Node;

typedef struct {
    Node** adjList;
    int* dist;
    int* visited;
    int n;
} Graph;

Node* createNode(int vertex, int cost) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->cost = cost;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjList = (Node**)malloc((n + 1) * sizeof(Node*));
    graph->dist = (int*)malloc((n + 1) * sizeof(int));
    graph->visited = (int*)malloc((n + 1) * sizeof(int));
    graph->n = n;
    for (int i = 1; i <= n; i++) {
        graph->adjList[i] = NULL;
        graph->dist[i] = INF;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v, int cost) {
    Node* newNode = createNode(v, cost);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;
}

void dijkstra(Graph* graph, int start) {
    graph->dist[start] = 0;

    for (int i = 1; i <= graph->n; i++) {
        int minDist = INF;
        int u = -1;

        for (int j = 1; j <= graph->n; j++) {
            if (!graph->visited[j] && graph->dist[j] < minDist) {
                minDist = graph->dist[j];
                u = j;
            }
        }

        if (u == -1) break;
        graph->visited[u] = 1;

        Node* temp = graph->adjList[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int cost = temp->cost;
            if (graph->dist[u] + cost < graph->dist[v]) {
                graph->dist[v] = graph->dist[u] + cost;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        scanf("%d %d %d", &u, &v, &cost);
        addEdge(graph, u, v, cost);
    }

    int start, end;
    scanf("%d %d", &start, &end);

    dijkstra(graph, start);

    printf("%d\n", graph->dist[end]);

    for (int i = 1; i <= n; i++) {
        Node* temp = graph->adjList[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }

    free(graph->adjList);
    free(graph->dist);
    free(graph->visited);
    free(graph);

    return 0;
}
