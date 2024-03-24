#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int sum = 0;

    for (int i = 0; i < n; i++) {
        char s[1000];
        scanf("%s", s);
        int l = strlen(s);

        int temp = 0;

        for (int j = 0; j < l; j++) {
            if (isdigit(s[j])) {
                if (temp == 0)
                    sum += ((s[j] - '0') * 10);

                temp = s[j] - '0';
            }
        }
        sum += temp;
    }
    printf("%d\n", sum);
}