#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int out = 0;

    for (int i = 0; i < n; i++) {
        char s[1000];
        scanf(" %[^\n]", s);
        int l = strlen(s);
        
        int gamein = 0;

        int flag = 0;

        for (int j = 0; j < l; j++) {
            if (isdigit(s[j])) {

                int dig1 = s[j] - '0';

                if (gamein == 0) {
                    if (!(isdigit(s[j + 1])))
                        gamein = s[j] - '0';
                    else if (s[j] == '1' && s[j + 1] == '0' && s[j + 2] == '0')
                        gamein = 100;
                    else
                        gamein = 10 * (s[j] - '0') + (s[j + 1] - '0');
                }

                else {
                    if (isdigit(s[j + 1])) {
                        if (dig1 > 1)
                            flag = 1;
                        else {
                            int dig2 = s[j + 1] - '0';
                            switch (s[j + 3]) {
                                case 'r':
                                    if (dig2 > 2)
                                        flag = 1;
                                    break;
                                case 'g':
                                    if (dig2 > 3)
                                        flag = 1;
                                    break;
                                case 'b':
                                    if (dig2 > 4)
                                        flag = 1;
                                    break;
                            }
                        }
                    }
                }
            }
        }

        if (flag == 0)
            out += gamein;
    }

    printf("%d\n", out);
}