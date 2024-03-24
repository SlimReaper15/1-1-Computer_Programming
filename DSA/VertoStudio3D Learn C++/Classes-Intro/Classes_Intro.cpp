#include <stdio.h>

// class Vertex {
//     float x, y, z; // Private by default
// };

// struct VertexStruct {
//     float x, y, z; // Public by default

//     void setToZero() { // Automatically has access to the struct VertexStruct
//         x = 0;
//         y = 0;
//         z = 0;
//     }

//     void set(float vx, float vy, float vz) {
//         x = vx;
//         y = vy;
//         z = vz;
//     }
// };

class Vertex {
private:
    float x, y, z;

public:
    void setToZero() {
        x = 0;
        y = 0;
        z = 0;
    }

    void set(float vx, float vy, float vz) {
        x = vx;
        y = vy;
        z = vz;
    }

    float getY() {
        return y;
    }
};

// The above type of class declaration is considered very bad practice, so what we do is:

int main() {
    // VertexStruct v, v2;
    // We're basically creating objects v and v2 whose members we can directly modify
    
    // v.x = 0;
    // v.y = 1;
    // v.z = 2;
    
    // Instead of the above 3 lines, we do:

    // v.set(0, 1, 2);
    
    // v2.x = 0;

    Vertex v, v2;

    // setToZero(); is wrong, it has nothing to operate on
    v.setToZero();

    // printf("%g\n", v.y);

    // Instead of printing v.y like this, we add a get method to the class

    printf("%g\n", v.getY());

    // Can access v.x, v.y, etc since data members of a struct are public

    return 0;
}

/* What is the difference between classes and structs
 * C++ expanded what a struct could do to make it more useful for object oriented programmers */