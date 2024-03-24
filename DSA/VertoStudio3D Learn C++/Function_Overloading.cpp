#include <stdio.h>

void func1() {
    printf("func1\n");
}

void func1(int x) {
    printf("func1 with argument %d\n", x);;
}

int main() {
    func1();
    func1(0);

    /* In C, this would give an error since we use func1 twice
     * But in C++, function overloading exists, the compiler determines which function we run depending on arguments
     * For example if we overlad printf we can avoid using format specifiers */
    
    return 0;
}
