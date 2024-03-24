#include <stdio.h>

struct Big {
    int x, y, z;
    int data[4096];
};

void func(Big &big) {
    /* Big &big does not mean the address of big
     * It means reference big, we have created a reference parameter
     * When we call it, we know that we're passing the variable in by reference */

    big = { }; // Is the same thing as doing b = in the original function
    // Reinitialises b to blank memory

    // big.x = 100;
}

int main() {
    Big b;
    b.x = 10;

    func(b);
    
    /* Now we no longer need to pass in &b, we can just pass in b
     * The compiler automatically grabs the address of b and creates the reference
     * We can't screw it up in a way that we could if we had involved pointers
     * Reference parameters are more restricted than pointers */
    
    printf("%d\n", b.x);

    float f = 5.0f;
    float &fr = f;

    fr = 2.0f; // Reference parameter to f

    printf("%g\n", f);

    return 0;
}