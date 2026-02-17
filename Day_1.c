#include <stdio.h>

int main() {
    int n, pos, x;

    // Read number of elements
    scanf("%d", &n);

    int arr[n + 1];  // Extra space for insertion

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read position (1-based) and element to insert
    scanf("%d", &pos);
    scanf("%d", &x);

    // Shift elements to the right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[pos - 1] = x;

    // Print updated array
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
