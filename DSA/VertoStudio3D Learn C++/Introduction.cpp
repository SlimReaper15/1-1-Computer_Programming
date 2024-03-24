#include <iostream>
using namespace std;

RidiculouslyLongType::SubType function() {

}

int main() {
    // Datatypes added

    bool b = true; // false

    int32_t i32 = 1; // Instead of assuming int is 4 bytes and short is 2 bytes, we can use these specific types
    uint64_t u64 = 0; // Unsigned
    // If we want a signed 8 bit integer
    int8_t i8 = 0;
    uint8_t u8;

    const char *str = "Hi there";
    string cppstr = "Hi there"; // Instead of the previous line

    auto a = 1.0f; // Compiler sees it as float, type inference
    auto 2 = 1; // int
    auto a3 = (double)1.0f; // double

    // RidiculouslyLongType::SubType ret == function();
    auto ret = function();
    
    return 0;
}