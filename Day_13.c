#include <stdio.h>

int main() {
    int r, c;

    // Read rows and columns
    scanf("%d %d", &r, &c);

    int A[r][c];

    // Read matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top <= bottom && left <= right) {

        // Traverse top row (left → right)
        for (int i = left; i <= right; i++)
            printf("%d ", A[top][i]);
        top++;

        // Traverse right column (top → bottom)
        for (int i = top; i <= bottom; i++)
            printf("%d ", A[i][right]);
        right--;

        // Traverse bottom row (right → left)
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", A[bottom][i]);
            bottom--;
        }

        // Traverse left column (bottom → top)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", A[i][left]);
            left++;
        }
    }

    return 0;
}
