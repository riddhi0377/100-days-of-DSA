#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int dfs(struct Node* adj[], int visited[], int recStack[], int v) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];
    while (temp != NULL) {
        int u = temp->data;

        if (!visited[u] && dfs(adj, visited, recStack, u))
            return 1;
        else if (recStack[u])
            return 1;

        temp = temp->next;
    }

    recStack[v] = 0;
    return 0;
}

int hasCycle(struct Node* adj[], int n) {
    int visited[n], recStack[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(adj, visited, recStack, i))
                return 1;
        }
    }

    return 0;
}

int main() {
    int n, m, u, v;

    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    if (hasCycle(adj, n))
        printf("YES");
    else
        printf("NO");

    return 0;
}