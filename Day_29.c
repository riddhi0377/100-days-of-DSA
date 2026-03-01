#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &n);

    if (n <= 0)
        return 0;

    // Create Linked List
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    // Find length and last node
    int length = 1;
    struct Node* tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    k = k % length;
    if (k == 0) {
        struct Node* curr = head;
        while (curr) {
            printf("%d ", curr->data);
            curr = curr->next;
        }
        return 0;
    }

    // Make circular
    tail->next = head;

    // Move to (length - k)th node
    int steps = length - k;
    struct Node* newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Update head
    head = newTail->next;

    // Break circle
    newTail->next = NULL;

    // Print rotated list
    struct Node* curr = head;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    return 0;
}