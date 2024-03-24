#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int n;
int *p;

ll min(ll a, ll b) {
    return (a < b) ? a : b;
}

ll mindiff(ll a, ll b, ll level) {
    if (level == n)
        return abs(a - b);

    return min(mindiff(a + p[level], b, level + 1), mindiff(a, b + level[p], level + 1));
}

int main() {
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    ll ans = mindiff(0, 0, 0);

    printf("%lld\n", ans);
}