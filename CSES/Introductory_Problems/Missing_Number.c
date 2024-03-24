#include <stdio.h>

typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);

    ll ideal = n * (n + 1LL) / 2LL;

    ll sum = 0;

    for (int i = 0; i < n - 1; i++) {
        int x;
        scanf("%d", &x);
        ideal -= x;
    }

    printf("%lld\n", ideal);
}