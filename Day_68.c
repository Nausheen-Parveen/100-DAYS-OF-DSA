/*A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

// Queue implementation
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, int x) {
    q->data[q->rear++] = x;
}

int dequeue(Queue *q) {
    return q->data[q->front++];
}

// Function to find alien dictionary order
char* alienOrder(char words[][100], int n) {
    static char result[27];
    
    int graph[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int present[MAX] = {0};

    // Mark all characters present
    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    // Build graph
    for (int i = 0; i < n - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];
        int len1 = strlen(w1);
        int len2 = strlen(w2);

        int found = 0;
        for (int j = 0; j < len1 && j < len2; j++) {
            if (w1[j] != w2[j]) {
                if (!graph[w1[j]-'a'][w2[j]-'a']) {
                    graph[w1[j]-'a'][w2[j]-'a'] = 1;
                    indegree[w2[j]-'a']++;
                }
                found = 1;
                break;
            }
        }

        // Invalid case: prefix issue
        if (!found && len1 > len2) {
            result[0] = '\0';
            return result;
        }
    }

    // Topological Sort (Kahn’s BFS)
    Queue q;
    initQueue(&q);

    for (int i = 0; i < MAX; i++) {
        if (present[i] && indegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    int index = 0;

    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        result[index++] = u + 'a';

        for (int v = 0; v < MAX; v++) {
            if (graph[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(&q, v);
                }
            }
        }
    }

    result[index] = '\0';

    // Check for cycle
    int count = 0;
    for (int i = 0; i < MAX; i++) {
        if (present[i]) count++;
    }

    if (index != count) {
        result[0] = '\0'; // cycle exists
    }

    return result;
}

// Driver Code
int main() {
    char words[][100] = {"baa", "abcd", "abca", "cab", "cad"};
    int n = 5;

    char *order = alienOrder(words, n);

    if (strlen(order) == 0) {
        printf("Invalid order\n");
    } else {
        printf("Alien Dictionary Order: %s\n", order);
    }

    return 0;
}
