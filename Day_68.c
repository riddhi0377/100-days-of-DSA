#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n, m, u, v;

    scanf("%d", &n);
    scanf("%d", &m);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    int queue[MAX], front = 0, rear = 0;

    // Push all nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                indegree[i]--;

                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    // Check cycle
    if (count != n)
        printf("\nCycle detected (Topo not possible)");

    return 0;
}