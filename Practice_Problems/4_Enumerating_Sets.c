#include <stdio.h>
#include <stdlib.h>

int n, k;
int *a;

void subsets(int subset[], int size, int curr) {
    if (size == k) {
        printf("{");
        for (int i = 0; i < k - 1; i++)
            printf("%d, ", subset[i]);
        printf("%d}, ", subset[k - 1]);
        return;
    }

    if (curr == n)
        return;

    subset[size] = a[curr];
    subsets(subset, size + 1, curr + 1);
    subsets(subset, size, curr + 1);
}

int main() {
    scanf("%d %d", &n, &k);

    a = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int subset[k];

    subsets(subset, 0, 0);
}