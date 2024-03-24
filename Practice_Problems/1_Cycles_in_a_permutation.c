#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    int map[n + 1]; // Fuck 0 indexing
    for (int i = 1; i <= n; i++)
        scanf("%d", &map[i]);

    int hash[n + 1]; // Keeps track of what mappings are over
    for (int i = 1; i <= n; i++)
        hash[i] = 0;

    for (int i = 1; i <= n; i++) {
        if (hash[i] == 1)
            continue;

        int temp = i;

        do {
            hash[temp] = 1;
            printf("%d->", temp);
            temp = map[temp];
        } while (temp != i);

        printf("%d\n", temp);
    }
}