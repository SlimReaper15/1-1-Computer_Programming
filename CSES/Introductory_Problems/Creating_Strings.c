#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **store;

int fact(int n) {
    int prod = 1;
    for (int i = 2; i <= n; i++)
        prod *= i;
    return prod;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int track = 0;

void permute(char *s, int l, int r) {
    if (l == r) {
        strcpy(store[track], s);
        track++;
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(s + l, s + i);
        permute(s, l + 1, r);
        swap(s + l, s + i); // Backtrack
    }
}

int comp(const void *a, const void *b) {
    char *a1 = *(char **)a;
    char *b1 = *(char **)b;
    return strcmp(a1, b1);
}

int main() {
    char s[9];
    scanf("%s", s);
    int n = strlen(s);

    int total = fact(n);

    store = (char **)malloc(total * sizeof(char *));
    for (int i = 0; i < total; i++)
        store[i] = (char *)malloc((n + 1) * sizeof(char));

    permute(s, 0, n - 1);
    
    qsort(store, total, sizeof(char *), comp);

    int count = 1;
    for (int i = 0; i < total - 1; i++) {
        if (strcmp(store[i + 1], store[i]) != 0)
            count++;
    }

    printf("%d\n%s\n", count, store[0]);

    for (int i = 0; i < total - 1; i++) {
        if (strcmp(store[i + 1], store[i]) != 0)
            printf("%s\n", store[i + 1]);
    }
}