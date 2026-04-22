#include <stdio.h>

#define MAX 1000

int main() {
    int arr[MAX], n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix = 0, maxLen = 0;

    int sumIndex[20001]; // to handle negative sums
    for (int i = 0; i < 20001; i++)
        sumIndex[i] = -2;

    sumIndex[10000] = -1; // sum = 0 at index -1

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        int key = prefix + 10000;

        if (sumIndex[key] != -2) {
            int len = i - sumIndex[key];
            if (len > maxLen)
                maxLen = len;
        } else {
            sumIndex[key] = i;
        }
    }

    printf("%d", maxLen);
    return 0;
}