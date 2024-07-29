#include <stdio.h>

typedef struct Node {
    char left;
    char right;
} Node;

Node tree[26];

void preorder(char node) {
    if (node == '.') return;
    printf("%c", node);
    preorder(tree[node - 'A'].left);
    preorder(tree[node - 'A'].right);
}

void inorder(char node) {
    if (node == '.') return;
    inorder(tree[node - 'A'].left);
    printf("%c", node);
    inorder(tree[node - 'A'].right);
}

void postorder(char node) {
    if (node == '.') return;
    postorder(tree[node - 'A'].left);
    postorder(tree[node - 'A'].right);
    printf("%c", node);
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char root, left, right;
        scanf(" %c %c %c", &root, &left, &right);
        tree[root - 'A'].left = left;
        tree[root - 'A'].right = right;
    }

    preorder('A');
    printf("\n");
    inorder('A');
    printf("\n");
    postorder('A');
    printf("\n");

    return 0;
}
