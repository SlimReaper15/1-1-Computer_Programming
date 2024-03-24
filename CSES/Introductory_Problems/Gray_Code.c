#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

char *tobin(int out) {
    char *s = (char *)malloc((n + 1) * sizeof(char));
    memset(s, '0', n * sizeof(char));
    s[n] = '\0';

    int track = 1;
    while (out != 0) {
        if ((out & 1) == 1)
            s[n - track] = '1';
        else
            s[n - track] = '0';

        track++;
        out = out >> 1;
    }

    return s;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < (1 << n); i++) {
        int out = i ^ (i >> 1);
        printf("%s\n", tobin(out));
    }
}