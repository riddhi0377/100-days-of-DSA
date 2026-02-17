#include <stdio.h>

int main() {
    int m, n;

    // Read rows and columns
    scanf("%d %d", &m, &n);

    int A[m][n];
    int sum = 0;

    // Read matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Add primary diagonal elements
    for (int i = 0; i < m && i < n; i++) {
        sum += A[i][i];
    }

    // Print result
    printf("%d", sum);

    return 0;
}
