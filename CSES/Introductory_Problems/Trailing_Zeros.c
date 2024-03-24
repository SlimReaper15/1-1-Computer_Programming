#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int count = 0;
    for (int i = 5; i <= n; i += 5) {
        int j = i;
        do {
            count++;
            j /= 5;
        } while (j % 5 == 0 && j != 0);
    }

    printf("%d\n", count);
}