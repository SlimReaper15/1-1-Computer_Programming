#include <string>
#include <stdio.h>

using namespace std;

int main() {

    string str = "Clown";

    // str = str.substr(2); // Skips the first 2 characters
    
    // str = str.substr(2, 2); // Skips 2, takes 2

    auto str2 = str;
    str[0] = '4';

    printf("%s\n", str2.c_str());

    const char *cs = str.c_str();
    printf("%s\n", cs);

    printf("%ld\n", str.length());

    return 0;
}