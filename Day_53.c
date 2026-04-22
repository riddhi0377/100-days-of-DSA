#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int hd;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++)
        nodes[i] = createNode(arr[i]);

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }
    return nodes[0];
}

struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[++q->front];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    if (!root) return 0;

    struct Queue q;
    q.front = q.rear = -1;

    root->hd = 0;
    enqueue(&q, root);

    int min = 0, max = 0;
    int vertical[200][200];
    int count[200] = {0};

    while (!isEmpty(&q)) {
        struct Node* temp = dequeue(&q);
        int hd = temp->hd;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        vertical[hd + 100][count[hd + 100]++] = temp->data;

        if (temp->left) {
            temp->left->hd = hd - 1;
            enqueue(&q, temp->left);
        }
        if (temp->right) {
            temp->right->hd = hd + 1;
            enqueue(&q, temp->right);
        }
    }

    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i + 100]; j++) {
            printf("%d ", vertical[i + 100][j]);
        }
        printf("\n");
    }

    return 0;
}