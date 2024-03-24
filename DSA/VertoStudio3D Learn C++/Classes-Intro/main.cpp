#include <stdio.h>
#include "vertex.h"

int main() {
    Vertex v, v2;

    v.setToZero();
    v.set(1, 2, 3);

    printf("%g\n", v.getY());

    return 0;
}