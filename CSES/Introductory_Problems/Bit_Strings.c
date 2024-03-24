#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int mod = 1e9 + 7;
    int prod = 1;

    for (int i = 0; i < n; i++)
        prod  = (prod * 2) % mod;

    printf("%d\n", prod);
}