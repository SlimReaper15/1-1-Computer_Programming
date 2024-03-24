#include <math.h>
#include <stdio.h>

// hanoi(disks, from, to, help) moves disks from from to to using help

void hanoi(int disks, int from, int to, int help) {
    if (disks == 1) {
        printf("%d %d\n", from, to);
        return;
    }
    
    hanoi(disks - 1, from, help, to);
    hanoi(1, from, to, help);
    hanoi(disks - 1, help, to, from);
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", (int)pow(2, n) - 1);

    hanoi(n, 1, 3, 2);
}