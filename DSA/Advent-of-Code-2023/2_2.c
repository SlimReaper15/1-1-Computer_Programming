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

        int r = 0, g = 0, b = 0;

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
                    int temp = 0;
                    char colour;

                    if (!(isdigit(s[j + 1]))) {
                        temp = dig1;
                        colour = s[j + 2];
                    }

                    else {
                        temp = 10 * dig1 + (s[j + 1] - '0');
                        colour = s[j + 3];
                    }

                    // temp contains the number of balls of colour 'colour'

                    switch (colour) {
                        case 'r':
                            if (temp > r)
                                r = temp;
                            break;
                        case 'g':
                            if (temp > g)
                                g = temp;
                            break;
                        case 'b':
                            if (temp > b)
                                b = temp;
                            break;
                    }
                }
            }
        }
        out += (r * g * b);
    }

    printf("%d\n", out);
}