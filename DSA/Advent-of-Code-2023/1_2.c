#include <ctype.h>
#include <stdio.h>
#include <string.h>

int substring(char *s, int start) {
    char three[4];
    char four[5];
    char five[6];

    strncpy(three, &s[start], 3);
    strncpy(four, &s[start], 4);
    strncpy(five, &s[start], 5);

    three[3] = '\0';
    four[4] = '\0';
    five[5] = '\0';

    if (strcmp(three, "one") == 0)
        return 1;
    else if (strcmp(three, "two") == 0)
        return 2;
    else if (strcmp(five, "three") == 0)
        return 3;
    else if (strcmp(four, "four") == 0)
        return 4;
    else if (strcmp(four, "five") == 0)
        return 5;
    else if (strcmp(three, "six") == 0)
        return 6;
    else if (strcmp(five, "seven") == 0)
        return 7;
    else if (strcmp(five, "eight") == 0)
        return 8;
    else if (strcmp(four, "nine") == 0)
        return 9;

    return 0;
}

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
            
            int store = substring(s, j);

            if (isdigit(s[j])) {
                if (temp == 0)
                    sum += ((s[j] - '0') * 10);

                temp = s[j] - '0';
            }

            else if (store) {
                if (temp == 0)
                    sum += (store * 10);

                temp = store;
            }
        }
        sum += temp;
    }
    printf("%d\n", sum);
}