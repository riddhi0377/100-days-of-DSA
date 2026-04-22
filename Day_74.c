#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];
    int count[MAX] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    int unique = 0;
    char uniqueNames[MAX][LEN];
    int freq[MAX] = {0};

    // Count votes
    for (int i = 0; i < n; i++) {
        int found = -1;

        for (int j = 0; j < unique; j++) {
            if (strcmp(names[i], uniqueNames[j]) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            strcpy(uniqueNames[unique], names[i]);
            freq[unique]++;
            unique++;
        } else {
            freq[found]++;
        }
    }

    // Find winner
    int maxVotes = -1;
    char winner[LEN];

    for (int i = 0; i < unique; i++) {
        if (freq[i] > maxVotes) {
            maxVotes = freq[i];
            strcpy(winner, uniqueNames[i]);
        } 
        else if (freq[i] == maxVotes) {
            if (strcmp(uniqueNames[i], winner) < 0) {
                strcpy(winner, uniqueNames[i]);
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}
