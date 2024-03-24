#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n;
    scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);

    qsort(x, n, sizeof(int), comp);

    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        if (x[i + 1] != x[i])
            count++;
    }

    printf("%d\n", count);
}