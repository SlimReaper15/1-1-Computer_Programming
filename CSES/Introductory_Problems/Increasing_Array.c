#include <stdio.h>

typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);

    ll count = 0;

    for (int i = 0; i < n - 1; i++) {
        if (x[i + 1] < x[i]) {
            count += x[i] - x[i + 1];
            x[i + 1] = x[i];
        }
    }
    printf("%lld\n", count);
}