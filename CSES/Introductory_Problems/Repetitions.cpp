#include <iostream>
using namespace std;

int main() {
    string x;
    cin >> x;

    char temp = x[0];
    int count = 1;
    int max = 1;
    int n = x.length();

    for (int i = 1; i < n; i++) {
        if (x[i] == temp)
            count++;

        else {
            count = 1;
            temp = x[i];
        }

        if (count > max)
            max = count;
    }
    printf("%d\n", max);
}