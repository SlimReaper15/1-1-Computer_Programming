#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    // 1-3 - Not possible
    // 3 1 4 2 for 4
    // 1 3 5 2 4 So odd numbers first and then even

    if (n == 2 || n == 3)
        printf("NO SOLUTION\n");
    
    else if (n == 4)
        printf("3 1 4 2\n");

    else {
        // Ceil(n / 2) odd numbers, n / 2 even numbers
        int c = (int)ceil(n / 2.0);
        for (int i = 0; i < c; i++)
            printf("%d ", 2 * i + 1);
        
        for (int i = 1; i <= n / 2; i++)
            printf("%d ", 2 * i);
    }
}