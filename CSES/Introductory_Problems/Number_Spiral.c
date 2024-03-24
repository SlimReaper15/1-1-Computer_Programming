#include <stdio.h>

typedef long long ll;

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int y, x;
        scanf("%d %d", &y, &x);

        ll max = (y > x) ? y : x;

        ll di = max * max - max + 1;

        if (max % 2 == 1)
            printf("%lld\n", di - (y - x));

        else
            printf("%lld\n", di + (y - x));
    }
}