#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point points[MAX * MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int x, int y) {
    q->points[q->rear].x = x;
    q->points[q->rear].y = y;
    q->rear++;
}

Point dequeue(Queue* q) {
    return q->points[q->front++];
}

int n, m;
int maze[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};  // 상, 하, 좌, 우
int dy[4] = {0, 0, -1, 1};  // 상, 하, 좌, 우

int bfs(int startX, int startY) {
    Queue q;
    initQueue(&q);
    enqueue(&q, startX, startY);
    visited[startX][startY] = 1;
    dist[startX][startY] = 1;

    while (!isEmpty(&q)) {
        Point p = dequeue(&q);
        int x = p.x;
        int y = p.y;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (maze[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    dist[nx][ny] = dist[x][y] + 1;
                    enqueue(&q, nx, ny);
                }
            }
        }
    }

    return dist[n-1][m-1];
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    int result = bfs(0, 0);
    printf("%d\n", result);

    return 0;
}
