#include <stdio.h>

#define SIZE 100
#define EMPTY -1

int table[SIZE];

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }
}

// Search using quadratic probing
int search(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY)
            return 0;

        if (table[idx] == key)
            return 1;
    }
    return 0;
}

int main() {
    int m, n;
    scanf("%d", &m);   // table size
    scanf("%d", &n);   // number of operations

    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    char op[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') { // INSERT
            insert(key, m);
        } else if (op[0] == 'S') { // SEARCH
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}