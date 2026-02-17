#include <stdio.h>

int main() {
    int n;

    // Read size of square matrix
    scanf("%d", &n);

    int A[n][n];

    // Read matrix elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int isIdentity = 1;

    // Check identity condition
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j) {
                // Diagonal elements must be 1
                if (A[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            } else {
                // Non-diagonal elements must be 0
                if (A[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if (!isIdentity)
            break;
    }

    if (isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
