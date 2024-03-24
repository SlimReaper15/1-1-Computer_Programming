#include <stdio.h>

typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);

    ll sum = n * (n + 1LL) / 2LL;

    if (sum % 2 == 1) {
        printf("NO\n");
        return 0;
    }

    else
        printf("YES\n");
    
    if (n % 4 == 3) {
        int newn = n - 3;
        int newstart = 4;

        printf("%d\n%d %d ", 2 + newn / 2, 1, 2);
        for (int i = 0; i < newn / 4; i++)
            printf("%d %d ", newstart + i, n - i);
        
        printf("\n%d\n%d ", 1 + newn / 2, 3);

        newstart += (newn / 4);
        n -= (newn / 4);

        for (int i = 0; i < newn / 4; i++)
            printf("%d %d ", newstart + i, n - i);
    }

    else if (n % 4 == 0) {
        int newstart = 1;

        printf("%d\n", n / 2);
        for (int i = 0; i < n / 4; i++)
            printf("%d %d ", newstart + i, n - i);
        
        printf("\n%d\n", n / 2);

        newstart += (n / 4);
        int ncopy = n - (n / 4);

        for (int i = 0; i < n / 4; i++)
            printf("%d %d ", newstart + i, ncopy - i);
    }
}