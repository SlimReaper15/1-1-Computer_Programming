#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    int hash[26] = {0};

    for (int i = 0; i < n; i++)
        hash[s[i] - 'A']++;
    
    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (hash[i] % 2 == 1)
            odd++;
    }

    if (odd > 1)
        printf("NO SOLUTION\n");
    
    for (int i = 0; i < 26; i++) {
        if (hash[i] % 2 == 0) {
            for (int j = 0; j < hash[i] / 2; j++)
                printf("%c", i + 'A');
        }
    }

    for (int i = 0; i < 26; i++) {
        if (hash[i] % 2 == 1) {
            for (int j = 0; j < hash[i]; j++)
                printf("%c", i + 'A');
        }
    }

    for (int i = 25; i >= 0; i--) {
        if (hash[i] % 2 == 0) {
            for (int j = 0; j < hash[i] / 2; j++)
                printf("%c", i + 'A');
        }
    }
}