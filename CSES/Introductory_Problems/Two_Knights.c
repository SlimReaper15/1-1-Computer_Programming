#include <stdio.h>

typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        ll total = (i * i) * (i * i - 1LL) / 2LL;
        
        ll ways = 4 * (i - 1) * (i - 2);

        printf("%lld\n", total - ways);
    }
}