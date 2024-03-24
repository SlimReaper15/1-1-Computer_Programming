#include <stdio.h>

struct Big {
    int x, y, z;
    int data[4096];
};

void func(Big *big) { // Read only - const Big *big
    big -> x = 100;
}

int main() {
    Big b;
    
    func(&b);
    // b is passed by reference
    printf("%d\n", b.x);

    return 0;
}